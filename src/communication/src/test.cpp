#include <ros/ros.h>
#include <communication/udp_server.h>
#include <communication/command.h>
#define MAXSIZE 1000
#define PORT 5001
#define TIME_BROKEN 300 //300s
#define TIME_WRONG 100 //100s

int main(int argc,char**argv)
{
	ros::init(argc,argv,"Server");
	ros::NodeHandle nh;
	ROS_INFO("start communication !");
	
	ros::Publisher pub=nh.advertise<communication::command>("comm/cmd",10);
	
	UDP_Server server;
	server.open();
	char send[MAXSIZE];
	char rec[MAXSIZE];
	server.init(PORT,send,rec,nh);
	ros::Rate rate(2);
	communication::command msg;
	
	while(ros::ok()&&server.time<TIME_BROKEN)
	{
		
		if(server.receive(MAXSIZE))
		{
			server.process();	
			msg.type=server.type;
			msg.command_lenth=server.cmd_lenth;
			msg.data=server.data_in;
			msg.break_flag=false;
			msg.wrong_flag=false;
			
			pub.publish(msg);
		}
		
		else 
		{
			if(server.time>TIME_WRONG)
			{
				msg.wrong_flag=true;
			}
			pub.publish(msg);
		}
		rate.sleep();
	}
	server.close_ser();
	while(ros::ok())
	{
		msg.break_flag=true;
		pub.publish(msg);
		rate.sleep();
	}
	return 0;
}
