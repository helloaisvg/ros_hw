
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

pcl::visualization::PCLVisualizer::Ptr viewer;

void pointCloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
  // 将 ROS 点云消息转换为 PCL 格式
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromROSMsg(*msg, *cloud);

  // 在可视化窗口中显示点云数据
  viewer->removeAllPointClouds();
  viewer->addPointCloud(cloud, "cloud");
  viewer->spinOnce();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "rshow_pc");
  ros::NodeHandle nh;

  // 创建点云订阅者，订阅 /rslidar_points 话题
  ros::Subscriber sub = nh.subscribe("/rslidar_points", 1, pointCloudCallback);

  // 创建 PCL 可视化窗口
  viewer.reset(new pcl::visualization::PCLVisualizer("PointCloud Viewer"));

  // 循环运行 ROS 节点
  ros::spin();

  return 0;
}
