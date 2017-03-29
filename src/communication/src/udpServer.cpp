#include <communication/udp_server.h>

UDP_Server::UDP_Server(bool timer_Flag):timer_Flag(timer_Flag)
{}

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

void UDP_Server::init(int port,char *send,char *rec,ros::NodeHandle &n)
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
    //sub_state=n.subscribe("/state",1,&UDP_Server::callback,this);
}

void UDP_Server::callback()
{
	// update the state;
}

bool UDP_Server::receive(int max)
{
	socklen_t addrlen;
	addrlen=sizeof(server);	
	
	int num=0;
	bzero(recBuf, sizeof(recBuf));
	
	num =recvfrom(sockfd,recBuf,max,0,(struct sockaddr*)&server,&addrlen); 
  	if(num>0)
  	{
  		printf("Received a string from client %s, string is: %s\n", 
				inet_ntoa(server.sin_addr), recBuf);
		/* 将收到的字符串消息返回给client端 */
		
		return true;
	}	
	else return false;
}

void UDP_Server::process()
{
	printf("data process\n");
	bzero(sendBuf, sizeof(sendBuf));
	
	int len=strlen(recBuf);
	socklen_t addrlen;
	addrlen=sizeof(server);	
	
	char *p=recBuf;
	string out;
	unsigned char head=*p++;
	out+=head;
	unsigned char order=*p++;
	out+=order;
	string ID;

	ID+=*p++;ID+=*p++;ID+=*p++;ID+=*p++;
	out+=ID;
	
	if(head==0x3F)
	{
		printf("head\n");
	} 
	
	// lenth
	
	//type
	unsigned char t=*p++;
	type+=t;
	out+=type;
	//data
	if(t==0x50)
	{
		printf("ask\n");
		if(timer_Flag)//if the timer has been opened ,clear the timer
		{
			time=0;
			
		}
		else 
		{
			// open the timer
		}
		
		// subscribe the data of state
	}
	else if(t==0x00)
	{
		time=0;
		char d=0x01;
		out+=d;
	}
	else 
	{
		char d=0x01;
		out+=d;
	}
	//check
	// check if correct
	
	//tail
	char tail=0x40;
	out+=tail;
    out+='\0';
    cout<<out.c_str()<<endl;
    //sendBack	
	sendBuf=(char *)out.c_str(); 
	sendto(sockfd,sendBuf, sizeof(sendBuf), 0, (struct sockaddr *)&server, addrlen);
}

void UDP_Server::close_ser()
{
	close(sockfd);  
	
}

int UDP_Server::timer()
{

}

