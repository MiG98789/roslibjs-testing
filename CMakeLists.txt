cmake_minimum_required(VERSION 2.8.3)
project(robowebtools)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs message_runtime
)

include_directories(include)
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/..
  ${catkin_INCLUDE_DIRS}
)

add_executable(arithmetic_node src/arithmetic.cpp)
target_link_libraries(arithmetic_node 
	${catkin_LIBRARIES}
)
