#include <communication/udp_client.h>


bool UDP_Client::open()
{
 	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) 
    	{
       		perror("Creatingsocket failed.");
       		 exit(1);
       		return false;
    	}
	else
	{
		printf("open ok\n");
		return true;
	}
}

void UDP_Client::init(int port,string ip)
{
	
   	 bzero(&client,sizeof(client));  
    	client.sin_family=AF_INET;		
    	client.sin_port=htons(port);	
    	client.sin_addr.s_addr= inet_addr(ip.c_str());
    	//printf("%s\n",ip.c_str() );
}

void UDP_Client::sendInfo(string type ,string data)
{
	socklen_t addrlen;
	addrlen=sizeof(client);	

	string cmdToPlc;
	char *sendBuf;	
	cmdToPlc+=type;
	cmdToPlc+=data;
	sendBuf=(char *)cmdToPlc.c_str();
	
	int out_len=cmdToPlc.size();
	cout<<"out_len "<<out_len<<endl;

	printf("send out %s\n",cmdToPlc.c_str());
	sendto(sockfd,sendBuf, out_len, 0, (struct sockaddr *)&client, addrlen);

}

void UDP_Client::close_ser()
{
	close(sockfd);  	
}
