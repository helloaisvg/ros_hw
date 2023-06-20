cmake_minimum_required(VERSION 3.0.2)
project(ros_hw)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  cv_bridge
  pcl_ros
)
find_package(OpenCV REQUIRED)
find_package(PCL REQUIRED)
catkin_package()

 
include_directories(
    #include
    ${catkin_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
    ${PCL_INCLUDE_DIRS}    
)

link_directories(
  ${PCL_LIBRARY_DIRS}
)

add_executable(${PROJECT_NAME}
  src/ros_hw.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)
 
add_executable(show_pc src/show_pc.cpp)
target_link_libraries(show_pc
  ${catkin_LIBRARIES}
  ${PCL_LIBRARIES}
)

