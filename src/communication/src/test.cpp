#include <ros/ros.h>
#include <communication/udp_server.h>

#define MAXSIZE 1000
#define PORT 5001


int main(int argc,char**argv)
{
	ros::init(argc,argv,"Server");
	ros::NodeHandle nh;
	ROS_INFO("start communication !");
	
	UDP_Server server;
	server.open();
	char send[MAXSIZE];
	char rec[MAXSIZE];
	server.init(PORT,send,rec);
	
	while(ros::ok())
	{
		server.receive(MAXSIZE);
	}
	server.close_ser();
	return 0;
}
