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

class UDP_Server
{

	public:
	//open udp
	bool open();
	/* initial the socket server;
		parameter: PORT
	*/
	void init(int port,char *send,char *rec);
	void process();
	void receive(int max);
	int timer();
	void close_ser();
	int sockfd;
	private:

	char *sendBuf;	
	char *recBuf;
	struct sockaddr_in server;
	struct sockaddr_in 	client;
};

#endif
