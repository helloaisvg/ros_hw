#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

void imageCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // 将ROS图像消息转换为OpenCV图像
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);

    // 显示图像
    cv::imshow("Image", cv_ptr->image);
    cv::waitKey(1);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("cv_bridge exception: %s", e.what());
  }
}

void depImageCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // 将ROS图像消息转换为OpenCV图像
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_32FC1);

    // 显示图像
    cv::imshow("DepthImage", cv_ptr->image);
    cv::waitKey(1);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("cv_bridge exception: %s", e.what());
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ros_hw");
  ros::NodeHandle nh;

  // 创建图像订阅者，订阅 /camera/color/image_raw 话题
  ros::Subscriber sub = nh.subscribe("/camera/color/image_raw", 5, imageCallback);
  ros::Subscriber depth_sub = nh.subscribe("/camera/depth/image_rect_raw", 5, depImageCallback);  

  // 创建OpenCV窗口
  cv::namedWindow("Image", cv::WINDOW_NORMAL);
  cv::namedWindow("DepthImage", cv::WINDOW_NORMAL);

  // 循环运行ROS节点
  ros::spin();

  // 关闭OpenCV窗口
  cv::destroyWindow("Image");
  cv::destroyWindow("DepthImage");


  return 0;
}
