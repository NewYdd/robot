#include "ros/ros.h"
#include <communication/sendCmd.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<communication::sendCmd>("send_Cmd");
  communication::sendCmd srv;
  srv.request.type= "C";
  srv.request. data= "D";
  if (client.call(srv)&&srv.response.receive)
  {
    ROS_INFO("sucess");
  }
  else
  {
    ROS_ERROR("Failed ");
    return 1;
  }

  return 0;
}