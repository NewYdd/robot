#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#include <cstring>
#include <string>
#include <iostream>
#include <ros/ros.h>
using namespace std;

class UDP_Server
{

	public:
	UDP_Server(bool timer=false);
	//open udp
	bool open();
	/* initial the socket server;
		parameter: PORT
	*/
	void init(int port,char *send,char *rec,ros::NodeHandle &n);
	void process();
	bool receive(int max);
	int timer();
	void close_ser();
	void callback();
	
	private:
	int sockfd;
	char *sendBuf;	
	char *recBuf;
	struct sockaddr_in server;
	struct sockaddr_in 	client;
	bool timer_Flag;
	
	public:
	int cmd_lenth;
	string type;
	
	int time;
	ros::Subscriber sub_state;
	
};

#endif
