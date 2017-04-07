#include <ros/ros.h>
#include <communication/udp_server.h>
#include <communication/command.h>
#define MAXSIZE 1000
#define PORT 5001
#define TIME_BROKEN 300 //300s
#define TIME_WRONG 20 //10s

int main(int argc,char**argv)
{
	ros::init(argc,argv,"Server");
	ros::NodeHandle nh;
	ROS_INFO("start communication !");
	
	UDP_Server server;
	server.open();
	char send[MAXSIZE];
	char rec[MAXSIZE];
	server.init(PORT,send,rec,nh);
	ros::Rate rate(2);
	
	server.wait(MAXSIZE,TIME_WRONG);
		

	return 0;
}
