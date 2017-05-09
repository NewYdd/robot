#include "ros/ros.h"
#include <communication/sendCmd.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<communication::sendCmd>("send_Cmd");
  communication::sendCmd srv;
  srv.request.type= "uuuuu";
  srv.request. data= "yyyyyy";
  if (client.call(srv))
  {
    ROS_INFO("sucess");
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}