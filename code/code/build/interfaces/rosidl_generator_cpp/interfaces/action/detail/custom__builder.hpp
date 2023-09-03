// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:action/Custom.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__CUSTOM__BUILDER_HPP_
#define INTERFACES__ACTION__DETAIL__CUSTOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/action/detail/custom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_Goal_distance
{
public:
  explicit Init_Custom_Goal_distance(::interfaces::action::Custom_Goal & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Custom_Goal distance(::interfaces::action::Custom_Goal::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_Goal msg_;
};

class Init_Custom_Goal_linear_velocity
{
public:
  Init_Custom_Goal_linear_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Custom_Goal_distance linear_velocity(::interfaces::action::Custom_Goal::_linear_velocity_type arg)
  {
    msg_.linear_velocity = std::move(arg);
    return Init_Custom_Goal_distance(msg_);
  }

private:
  ::interfaces::action::Custom_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_Goal>()
{
  return interfaces::action::builder::Init_Custom_Goal_linear_velocity();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_Result_success
{
public:
  Init_Custom_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Custom_Result success(::interfaces::action::Custom_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_Result>()
{
  return interfaces::action::builder::Init_Custom_Result_success();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_Feedback_distance_to_target
{
public:
  Init_Custom_Feedback_distance_to_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Custom_Feedback distance_to_target(::interfaces::action::Custom_Feedback::_distance_to_target_type arg)
  {
    msg_.distance_to_target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_Feedback>()
{
  return interfaces::action::builder::Init_Custom_Feedback_distance_to_target();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_SendGoal_Request_goal
{
public:
  explicit Init_Custom_SendGoal_Request_goal(::interfaces::action::Custom_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Custom_SendGoal_Request goal(::interfaces::action::Custom_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_SendGoal_Request msg_;
};

class Init_Custom_SendGoal_Request_goal_id
{
public:
  Init_Custom_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Custom_SendGoal_Request_goal goal_id(::interfaces::action::Custom_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Custom_SendGoal_Request_goal(msg_);
  }

private:
  ::interfaces::action::Custom_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_SendGoal_Request>()
{
  return interfaces::action::builder::Init_Custom_SendGoal_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_SendGoal_Response_stamp
{
public:
  explicit Init_Custom_SendGoal_Response_stamp(::interfaces::action::Custom_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Custom_SendGoal_Response stamp(::interfaces::action::Custom_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_SendGoal_Response msg_;
};

class Init_Custom_SendGoal_Response_accepted
{
public:
  Init_Custom_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Custom_SendGoal_Response_stamp accepted(::interfaces::action::Custom_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Custom_SendGoal_Response_stamp(msg_);
  }

private:
  ::interfaces::action::Custom_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_SendGoal_Response>()
{
  return interfaces::action::builder::Init_Custom_SendGoal_Response_accepted();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_GetResult_Request_goal_id
{
public:
  Init_Custom_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Custom_GetResult_Request goal_id(::interfaces::action::Custom_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_GetResult_Request>()
{
  return interfaces::action::builder::Init_Custom_GetResult_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_GetResult_Response_result
{
public:
  explicit Init_Custom_GetResult_Response_result(::interfaces::action::Custom_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Custom_GetResult_Response result(::interfaces::action::Custom_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_GetResult_Response msg_;
};

class Init_Custom_GetResult_Response_status
{
public:
  Init_Custom_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Custom_GetResult_Response_result status(::interfaces::action::Custom_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Custom_GetResult_Response_result(msg_);
  }

private:
  ::interfaces::action::Custom_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_GetResult_Response>()
{
  return interfaces::action::builder::Init_Custom_GetResult_Response_status();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Custom_FeedbackMessage_feedback
{
public:
  explicit Init_Custom_FeedbackMessage_feedback(::interfaces::action::Custom_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Custom_FeedbackMessage feedback(::interfaces::action::Custom_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Custom_FeedbackMessage msg_;
};

class Init_Custom_FeedbackMessage_goal_id
{
public:
  Init_Custom_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Custom_FeedbackMessage_feedback goal_id(::interfaces::action::Custom_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Custom_FeedbackMessage_feedback(msg_);
  }

private:
  ::interfaces::action::Custom_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Custom_FeedbackMessage>()
{
  return interfaces::action::builder::Init_Custom_FeedbackMessage_goal_id();
}

}  // namespace interfaces

#endif  // INTERFACES__ACTION__DETAIL__CUSTOM__BUILDER_HPP_
