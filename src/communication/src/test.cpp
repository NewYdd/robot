#include <ros/ros.h>
#include <communication/udp_server.h>
#include <communication/command.h>
#define MAXSIZE 1000
#define PORT 8001
#define TIME_BROKEN 30 //300s
#define TIME_WRONG 6//10s

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
	
	
	while(ros::ok()&&!server.broken)
	{
		server.wait_connect(MAXSIZE,1000);
		server.wait_command(MAXSIZE,TIME_WRONG); //receive message , timeout break;
		printf("wait  reconnect\n");
		server.wait_reconnect(MAXSIZE,TIME_BROKEN);
		
	}	
	printf("communication failed\n");
	server.close_ser();
	return 0;
}
