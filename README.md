# ros_hw

## build 
```
catkin_make
```

## run

```
terminator 1:
$ roscore

terminator 2:
$ cd bag_dir
$ rosbag play all.bag

terminator 3:
$ rosbag  info  all.bag 
path:        all.bag
version:     2.0
duration:    1:19s (79s)
start:       Nov 11 2022 18:29:12.63 (1668162552.63)
end:         Nov 11 2022 18:30:32.47 (1668162632.47)
size:        4.2 GB
messages:    30899
compression: none [5103/5103 chunks]
types:       nav_msgs/Odometry       [cd5e73d190d741a2f92e81eda573aca7]
             sensor_msgs/CameraInfo  [c9a58c1b0b154e0e6da7578cb991d214]
             sensor_msgs/Image       [060021388200f6f0f447d0fcd9c64743]
             sensor_msgs/Imu         [6a62c6daae103f4ff57a132d6f95cec2]
             sensor_msgs/LaserScan   [90c7ef2dc6895d81024acba2ac42f369]
             sensor_msgs/PointCloud2 [1158d486dd51d683ce2f1be655c3c181]
             tf2_msgs/TFMessage      [94810edda583a504dfda3829e70d7eec]
topics:      /camera/color/camera_info       1910 msgs    : sensor_msgs/CameraInfo 
             /camera/color/image_raw         1910 msgs    : sensor_msgs/Image      
             /camera/depth/camera_info       2393 msgs    : sensor_msgs/CameraInfo 
             /camera/depth/image_rect_raw    2393 msgs    : sensor_msgs/Image      
             /imu/data_raw                  15903 msgs    : sensor_msgs/Imu        
             /odom                            799 msgs    : nav_msgs/Odometry      
             /rslidar_points                  799 msgs    : sensor_msgs/PointCloud2
             /scan                            799 msgs    : sensor_msgs/LaserScan  
             /tf                             3991 msgs    : tf2_msgs/TFMessage      (5 connections)
             /tf_static                         2 msgs    : tf2_msgs/TFMessage      (2 connections)

terminator 4:
$ rostopic  echo  /odom 

terminator 5:
$ rostopic  echo  /imu/data_raw 

terminator 6:
$ source ./devel/setup.bash
$ rosrun  ros_hw ros_hw

terminator 7:
$ source ./devel/setup.bash
$ rosrun  ros_hw show_pc

```
