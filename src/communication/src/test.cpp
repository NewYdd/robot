#include <ros/ros.h>
#include <communication/udp_server.h>
#include <communication/command.h>
#define MAXSIZE 1000
#define PORT 5001
#define TIME_ERROR 300 //300s
#define TIME_WRONG 100 //100s

int main(int argc,char**argv)
{
	ros::init(argc,argv,"Server");
	ros::NodeHandle nh;
	ROS_INFO("start communication !");
	
	ros::Publisher pub=nh.advertise<communication::command>("command",10);
	
	UDP_Server server;
	server.open();
	char send[MAXSIZE];
	char rec[MAXSIZE];
	server.init(PORT,send,rec,nh);
	ros::Rate rate(2);
	communication::command msg;
	
	while(ros::ok()&&server.time<TIME_ERROR)
	{
		
		if(server.receive(MAXSIZE))
		{
			server.process();
			
			msg.type=server.type;
			msg.command_lenth=server.cmd_lenth;
			//
			//
			pub.publish(msg);
		}
		
		else 
		{
			if(server.time>TIME_WRONG)
			{
			
			 // pub the communication abort
			}
			pub.publish(msg);
		}
		rate.sleep();
	}
	
	server.close_ser();
	return 0;
}
