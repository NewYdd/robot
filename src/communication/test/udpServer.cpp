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
	{
		printf("open ok\n");
		return true;
	}
}

void UDP_Server::init(int port,char *send,char *rec,ros::NodeHandle &n)
{
	broken=false;
   	connect=false;
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
	pub_command=n.advertise<communication::command>("comm/cmd",10);
}

void UDP_Server::callback()
{
	// update the state;
}

void UDP_Server::wait_command(int maxsize,int time)
{
	fd_set fds;
	timeval timeout={time,0};
	int net;
	connect=true;
	
	while(1)
	{
		printf("connected\n");
		FD_ZERO(&fds);
		FD_SET(sockfd,&fds);
		net=0;
		net=select(sockfd+1,&fds,NULL,NULL,&timeout);
		
		if(net<0)
		{
			exit(-1);
		}
		else if(net==0) 
		{
			printf("timeout\n");
			pub_msg.wrong_flag=true;
			pub_msg.break_flag=false;
			pub_command.publish(pub_msg);
			connect=false;	
			break;
		}
				
		 else
		 {	if(FD_ISSET(sockfd,&fds))
				{
					receive(maxsize);
					pub_msg.type=type;
					pub_msg.command_lenth=cmd_lenth;
					pub_msg.data=data_in;
					pub_msg.break_flag=false;
					pub_msg.wrong_flag=false;
					
					pub_command.publish(pub_msg);
					
				}
				
		 }
	
	}
}
void UDP_Server::wait_connect(int maxsize,int time)
{
	fd_set fds;
	timeval timeout={time,0};
	int net;
	
	while(!connect)
	{
		printf("connecting\n");
		FD_ZERO(&fds);
		FD_SET(sockfd,&fds);
		net=0;
		net=select(sockfd+1,&fds,NULL,NULL,&timeout);
	
		if(net<0)
		{
			exit(-1);
		}
		else if(net==0) 
		{
			printf("timeout\n");
			pub_msg.wrong_flag=true;
			pub_msg.break_flag=true;
			pub_command.publish(pub_msg);
			broken=true;
			break;
		}
				
		 else
		 {	if(FD_ISSET(sockfd,&fds))
				{
					receive(maxsize);
					if(connect)
						printf("reconnect sucess\n");
					pub_msg.type=type;
					pub_msg.command_lenth=cmd_lenth;
					pub_msg.data=data_in;
					pub_msg.break_flag=false;
					pub_msg.wrong_flag=!connect;
					pub_command.publish(pub_msg);
					
				}
				
		 }
	
	}
	
}


void UDP_Server::receive(int max)
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
		process();
		
	}	
	
}

void UDP_Server::process()
{

	bzero(sendBuf, sizeof(sendBuf));

	int len=strlen(recBuf);
	socklen_t addrlen;
	addrlen=sizeof(server);	
	
	char *p=recBuf;
	string out;
	
	unsigned char head=*p++;
	unsigned char order=*p++;
	string ID="";
	string data="";
	ID+=*p++;ID+=*p++;ID+=*p++;ID+=*p++;

	// lenth
	unsigned char lenth[]={0,0};
	lenth[0]=*p++;
	lenth[1]=*p++;
	
	//for processor
	cmd_lenth=0;
	cmd_lenth=(int)lenth[0]*256+(int)lenth[1];
	
	unsigned char t=*p++;
	
	for(int i=0;i<cmd_lenth-1;i++)
	{
		data+=*p++;
	}
	unsigned char check=*p++;
	unsigned char tail=*p;
	
	unsigned char check_out;//crc
	unsigned char rec=0x01; //receive normal   as data
	
	out+=head;
	out+=order;
	out+=ID;
	char len_out[2];
	len_out[0]=0x00;
	len_out[1]=0x02;
			
	if(tail==0xFF)
	{
		printf("command  all\n");
		//scheck_out=getCrc(data);
		check_out=0x00;   **if you want test  ,use this sentence
		if(check==check_out)
		{	
			type="";
			data_in="";
			// for processor
			type+=t;
			data_in=data;	
			//data
			if(t==0x50)  // ask for state information
			{
				printf("ask\n");
				len_out[0]=0x00;
				len_out[1]=0x26;
				out+=(char *)len_out;
				out+=t;
				out+=rec;
				out+=data_out;
				check_out=getCrc(out);// update crc		
			}
			else if(t==0x00)
			{
				printf("connect command\n");
				out+=(char *)len_out;
				out+=t;
				out+=rec;
				check_out=getCrc(out);
				connect=true;
			}
			else 
			{ 
				out+=(char *)len_out;
				out+=t;
				out+=rec;
				check_out=getCrc(out);
			}// update crc
		}
		else// check failed ,return receive error
		{	
			out+=(char *)len_out;
			out+=t;
			rec=0x00;
			out+=rec;
			check_out=getCrc(out);// update crc
		}
	}
	
	else //the command not compelete 
	{	
		out+=(char *)len_out;
		out+=t;
		rec=0x00;
		out+=rec;
		check_out=getCrc(out);// default check_out 
	}
		
	out+=check_out;
	out+=tail;
    
    	cout<<out.c_str()<<endl;
	sendBuf=(char *)out.c_str(); 
	sendto(sockfd,sendBuf, sizeof(sendBuf), 0, (struct sockaddr *)&server, addrlen);
}

unsigned char UDP_Server::getCrc(string values)
{
	unsigned char crc_array[256] = {
		0x00, 0x5e, 0xbc, 0xe2, 0x61, 0x3f, 0xdd, 0x83,
		0xc2, 0x9c, 0x7e, 0x20, 0xa3, 0xfd, 0x1f, 0x41,
		0x9d, 0xc3, 0x21, 0x7f, 0xfc, 0xa2, 0x40, 0x1e,
		0x5f, 0x01, 0xe3, 0xbd, 0x3e, 0x60, 0x82, 0xdc,
		0x23, 0x7d, 0x9f, 0xc1, 0x42, 0x1c, 0xfe, 0xa0,
		0xe1, 0xbf, 0x5d, 0x03, 0x80, 0xde, 0x3c, 0x62,
		0xbe, 0xe0, 0x02, 0x5c, 0xdf, 0x81, 0x63, 0x3d,
		0x7c, 0x22, 0xc0, 0x9e, 0x1d, 0x43, 0xa1, 0xff,
		0x46, 0x18, 0xfa, 0xa4, 0x27, 0x79, 0x9b, 0xc5,
		0x84, 0xda, 0x38, 0x66, 0xe5, 0xbb, 0x59, 0x07,
		0xdb, 0x85, 0x67, 0x39, 0xba, 0xe4, 0x06, 0x58,
		0x19, 0x47, 0xa5, 0xfb, 0x78, 0x26, 0xc4, 0x9a,
		0x65, 0x3b, 0xd9, 0x87, 0x04, 0x5a, 0xb8, 0xe6,
		0xa7, 0xf9, 0x1b, 0x45, 0xc6, 0x98, 0x7a, 0x24,
		0xf8, 0xa6, 0x44, 0x1a, 0x99, 0xc7, 0x25, 0x7b,
		0x3a, 0x64, 0x86, 0xd8, 0x5b, 0x05, 0xe7, 0xb9,
		0x8c, 0xd2, 0x30, 0x6e, 0xed, 0xb3, 0x51, 0x0f,
		0x4e, 0x10, 0xf2, 0xac, 0x2f, 0x71, 0x93, 0xcd,
		0x11, 0x4f, 0xad, 0xf3, 0x70, 0x2e, 0xcc, 0x92,
		0xd3, 0x8d, 0x6f, 0x31, 0xb2, 0xec, 0x0e, 0x50,
		0xaf, 0xf1, 0x13, 0x4d, 0xce, 0x90, 0x72, 0x2c,
		0x6d, 0x33, 0xd1, 0x8f, 0x0c, 0x52, 0xb0, 0xee,
		0x32, 0x6c, 0x8e, 0xd0, 0x53, 0x0d, 0xef, 0xb1,
		0xf0, 0xae, 0x4c, 0x12, 0x91, 0xcf, 0x2d, 0x73,
		0xca, 0x94, 0x76, 0x28, 0xab, 0xf5, 0x17, 0x49,
		0x08, 0x56, 0xb4, 0xea, 0x69, 0x37, 0xd5, 0x8b,
		0x57, 0x09, 0xeb, 0xb5, 0x36, 0x68, 0x8a, 0xd4,
		0x95, 0xcb, 0x29, 0x77, 0xf4, 0xaa, 0x48, 0x16,
		0xe9, 0xb7, 0x55, 0x0b, 0x88, 0xd6, 0x34, 0x6a,
		0x2b, 0x75, 0x97, 0xc9, 0x4a, 0x14, 0xf6, 0xa8,
		0x74, 0x2a, 0xc8, 0x96, 0x15, 0x4b, 0xa9, 0xf7,
		0xb6, 0xe8, 0x0a, 0x54, 0xd7, 0x89, 0x6b, 0x35,
	};
	unsigned char crc8 = 0;
	for (int i = 0; i < values.size(); i++)
	{
		crc8 = crc_array[crc8^(unsigned char)(values[i])];
	}
	return crc8;
}



void UDP_Server::close_ser()
{
	close(sockfd);  	
}


