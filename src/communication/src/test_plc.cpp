#include <ros/ros.h>
#include <communication/udp_client.h>
#include <communication/sendCmd.h>

#define	UDP_TEST_PORT		8001
#define UDP_SERVER_IP 		"192.168.60.169"

bool sendCallback(communication::sendCmd::Request  &req,
         communication::sendCmd::Response &res) ; 

UDP_Client client;
int main(int argc,char ** argv)
{
	ros::init(argc,argv,"command_to_plc");
	ros::NodeHandle nh;
	ros::ServiceServer send_Cmd = nh.advertiseService("send_Cmd", sendCallback);
	
	client.open();
	client.init(UDP_TEST_PORT,UDP_SERVER_IP);
  	ROS_INFO("Ready to send_Cmd");
  	ros::spin();
	return 0;
}

bool sendCallback(communication::sendCmd::Request  &req,
         communication::sendCmd::Response &res) 
{
            // send command and return somethin 
	client.sendInfo(req.type,req.data);
 	 return true;
}
