#include <communication/udp_server.h>
	
bool UDP_Server::open()
{
	 if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) 
    {
       perror("Creatingsocket failed.");
       // exit(1);
       return false;
    }
	else
		printf("open ok\n");
		return true;
}

void UDP_Server::init(int port,char *send,char *rec)
{
	bzero(&server,sizeof(server));  
    server.sin_family=AF_INET;		
    server.sin_port=htons(port);	
    server.sin_addr.s_addr= htonl (INADDR_ANY);
    if(bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
       perror("Bind()error.");
      // exit(1);
    }   
    fcntl(sockfd,F_SETFL,O_NONBLOCK);
    sendBuf=send;
    recBuf=rec;
}

void UDP_Server::receive(int max)
{
	
	int num=0;
	bzero(recBuf, sizeof(recBuf));
	socklen_t addrlen;
	addrlen=sizeof(server);	
	num =recvfrom(sockfd,recBuf,max,0,(struct sockaddr*)&server,&addrlen); 
  	if(num>0)
  	{
  		printf("Received a string from client %s, string is: %s\n", 
				inet_ntoa(server.sin_addr), recBuf);
		/* 将收到的字符串消息返回给client端 */
		//process();
		sendto(sockfd,sendBuf, sizeof(sendBuf), 0, (struct sockaddr *)&server, addrlen);
		
	}	
}

void UDP_Server::process()
{

}

void UDP_Server::close_ser()
{
	close(sockfd);  
	
}

int UDP_Server::timer()
{

}

