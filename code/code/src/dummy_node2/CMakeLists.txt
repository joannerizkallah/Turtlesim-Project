cmake_minimum_required(VERSION 3.8)
project(dummy_node2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(CMAKE_PREFIX_PATH ../../build/dummy_node2/_deps/json-build)
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(interfaces REQUIRED)
find_package(nlohmann_json REQUIRED)

add_library(action_client SHARED
  src/dummy_cpp_node.cpp)
target_include_directories(action_client PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(action_client
  interfaces
  rclcpp
  rclcpp_action
  rclcpp_components
  nlohmann_json)
rclcpp_components_register_node(action_client PLUGIN "action_cpp::CustomActionClient" EXECUTABLE dummy_cpp_node)
target_include_directories(action_client PUBLIC ${nlohmann_json_INCLUDE_DIRS})
install(TARGETS
  action_client
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
include_directories(
          PUBLIC
          $<INSTALL_INTERFACE:include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
)
target_link_libraries(action_client nlohmann_json::nlohmann_json)

add_library(dummy_client SHARED src/dummy_cpp_lib.cpp)
ament_target_dependencies(dummy_client rclcpp std_msgs nlohmann_json)

install(TARGETS dummy_client EXPORT ${PROJECT_NAME}Targets)
#install(DIRECTORY include/${PROJECT_NAME} DESTINATION include/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME}/)
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

ament_package()
