cmake_minimum_required(VERSION 3.8)
project(dummy_node1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

add_library(action_server SHARED
  src/dummy_cpp_node.cpp)


target_include_directories(action_server PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  )
ament_target_dependencies(action_server
  interfaces
  rclcpp
  rclcpp_action
  rclcpp_components
  geometry_msgs)
rclcpp_components_register_node(action_server PLUGIN "action_cpp::CustomActionServer" EXECUTABLE dummy_cpp_node)
install(TARGETS
  action_server
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
include_directories(
          PUBLIC
          $<INSTALL_INTERFACE:include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
)

add_library(dummy_server SHARED src/dummy_cpp_lib.cpp)
ament_target_dependencies(dummy_server rclcpp std_msgs geometry_msgs)
install(TARGETS dummy_server EXPORT ${PROJECT_NAME}Targets)
#install(DIRECTORY include/${PROJECT_NAME} DESTINATION include/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME}/)
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

ament_package()
