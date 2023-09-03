#include <functional>
#include <memory>
#include <thread>

#include "geometry_msgs/msg/twist.hpp"

#include "interfaces/action/custom.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "chrono"
#include <string>

namespace action_cpp
{
class CustomActionServer : public rclcpp::Node
{
public:
  using Custom = interfaces::action::Custom;
  using GoalHandleCustom = rclcpp_action::ServerGoalHandle<Custom>;
  double max_vel = 0.5;
  explicit CustomActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("custom_action_server", options)
  {
    using namespace std::placeholders;
    
    this->action_server_ = rclcpp_action::create_server<Custom>(
      this,
      "custom",
      std::bind(&CustomActionServer::handle_goal, this, _1, _2),
      std::bind(&CustomActionServer::handle_cancel, this, _1),
      std::bind(&CustomActionServer::handle_accepted, this, _1));
      //this->declare_parameter("default_max_linear_velocity","");
      //max_vel = this->get_parameter("default_max_linear_velocity").as_double();
      
  }

private:
	rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp_action::Server<Custom>::SharedPtr action_server_;

  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const Custom::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Received goal request");
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleCustom> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandleCustom> goal_handle)
  {
    using namespace std::placeholders;
    std::thread{std::bind(&CustomActionServer::execute, this, _1), goal_handle}.detach();
  }

  void execute(const std::shared_ptr<GoalHandleCustom> goal_handle)
  {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    rclcpp::Rate loop_rate(3);
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<Custom::Feedback>();
    auto & distanceToTarget_ = feedback->distance_to_target;
    auto result = std::make_shared<Custom::Result>();
    auto velocity_ = goal->linear_velocity;
    auto distance_ = goal-> distance; 
    distanceToTarget_ = distance_;
   publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 1000);
    if(velocity_> max_vel) {
    	velocity_ = max_vel;
    }
    
    while(rclcpp::ok() && distanceToTarget_ >0) {
      // Check if there is a cancel request
      //if (goal_handle->is_canceling()) {
        //result->success= false;
        //goal_handle->canceled(result);
        //RCLCPP_INFO(this->get_logger(), "Goal canceled");
        //return;
      //}
      // Update distanceToTarget
      end = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed_seconds = end - start;
      distanceToTarget_ = distance_ - (elapsed_seconds*velocity_).count();
      // Publish feedback
      goal_handle->publish_feedback(feedback);
      //move turtle sim
      geometry_msgs::msg::Twist msg;
      msg.linear.x += (elapsed_seconds*velocity_).count();
      publisher_->publish(msg);
      
      RCLCPP_INFO(this->get_logger(), "Running ");

      loop_rate.sleep();
	}
    // Check if goal is done
    if (rclcpp::ok() && distanceToTarget_<0) {
      result->success = true;
      goal_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }
  }
};  // class CustomActionServer

}  // namespace action_cpp
RCLCPP_COMPONENTS_REGISTER_NODE(action_cpp::CustomActionServer)

