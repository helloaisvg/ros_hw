cmake_minimum_required(VERSION 3.0.2)
project(ros_hw)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  cv_bridge
)
find_package(OpenCV REQUIRED)

catkin_package()

 
include_directories(
    #include
    ${catkin_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
  src/ros_hw.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)
 
