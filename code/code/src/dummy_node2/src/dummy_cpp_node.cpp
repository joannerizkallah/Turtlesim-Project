#include <functional>
#include <future>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include "interfaces/action/custom.hpp"
#include <nlohmann/json.hpp>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
using json = nlohmann::json;
namespace action_cpp
{
class CustomActionClient : public rclcpp::Node
{
public:
  using Custom = interfaces::action::Custom;
  using GoalHandleCustom = rclcpp_action::ClientGoalHandle<Custom>;

  explicit CustomActionClient(const rclcpp::NodeOptions & options)
  : Node("custom_action_client", options)
  {
    this->client_ptr_ = rclcpp_action::create_client<Custom>(
      this,
      "custom");
	this->timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&CustomActionClient::send_goal, this));
  }

  void send_goal()
  {
    using namespace std::placeholders;
    
    this->timer_->cancel();
    
    if (!this->client_ptr_) {
      RCLCPP_ERROR(this->get_logger(), "Action client not initialized");
    }
    
    if (!this->client_ptr_->wait_for_action_server()) {
      RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
      rclcpp::shutdown();
    }
    //std::ifstream stream("config/config.json");
    //stream.open("config/config.json");
    //json j = json::parse(stream);
    
    auto goal_msg = Custom::Goal();
    //std::vector<json> commands = j["commands"];
    //    for (const auto& command : commands) {
    //if (command.contains("linear_velocity") && command.contains("distance")) {
       // double v = command["linear_velocity"];
	//double d = command["distance"];
	//goal_msg.linear_velocity = v;
	//goal_msg.distance = d;
	//}
    //}
    goal_msg.linear_velocity = 10;
    goal_msg.distance = 30;
    RCLCPP_INFO(this->get_logger(), "Sending goal");

    auto send_goal_options = rclcpp_action::Client<Custom>::SendGoalOptions();
    send_goal_options.goal_response_callback =
      std::bind(&CustomActionClient::goal_response_callback, this, _1);
    send_goal_options.feedback_callback =
      std::bind(&CustomActionClient::feedback_callback, this, _1, _2);
    send_goal_options.result_callback =
      std::bind(&CustomActionClient::result_callback, this, _1);
    auto goal_handle_future = this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
  }

private:
  rclcpp_action::Client<Custom>::SharedPtr client_ptr_;
  rclcpp::TimerBase::SharedPtr timer_;
  bool goal_done_;
  
  void goal_response_callback(const GoalHandleCustom::SharedPtr & goal_handle)
  {
    if (!goal_handle) {
      RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    } else {
      RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
    }
  }

  void feedback_callback(
    GoalHandleCustom::SharedPtr,
    const std::shared_ptr<const Custom::Feedback> feedback)
  {
  RCLCPP_INFO(
      this->get_logger(),
      "Distance left is %f", feedback->distance_to_target);
  }

  void result_callback(const GoalHandleCustom::WrappedResult & result)
  {
 
 this->goal_done_ = true;
   // switch (result.code) {
     // case rclcpp_action::ResultCode::SUCCEEDED:
      //  break;
      //case rclcpp_action::ResultCode::ABORTED:
       // RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
       // return;
      //case rclcpp_action::ResultCode::CANCELED:
      //  RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
      //  return;
      //default:
      //  RCLCPP_ERROR(this->get_logger(), "Unknown result code");
      //  return;
   // }
    RCLCPP_INFO(this->get_logger(), "%d", result.result->success);
    rclcpp::shutdown();
    }
    

};  // class CustomActionClient

}  // namespace action_cpp
RCLCPP_COMPONENTS_REGISTER_NODE(action_cpp::CustomActionClient)
