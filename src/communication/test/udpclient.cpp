#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <signal.h>
#include <unistd.h>

#define	UDP_TEST_PORT		5001
#define UDP_SERVER_IP 		"192.168.60.169"

int main(int argC, char* arg[])
{
	struct sockaddr_in addr;
	int sockfd, len = 0;	
	socklen_t addr_len = sizeof(struct sockaddr_in);		
	char buffer[256];

	/* 建立socket，注意必须是SOCK_DGRAM */
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}

	/* 填写sockaddr_in*/
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(UDP_TEST_PORT);
	addr.sin_addr.s_addr = inet_addr(UDP_SERVER_IP);
	buffer[0]=0xFA;
	buffer[1]=0x00;
	buffer[2]=0x21;buffer[3]=0x21;buffer[4]=0x21;buffer[5]=0x21;

	buffer[6]=0x00;buffer[7]=0x02;
	buffer[8]=0x00;
	buffer[9]=0x01;
	buffer[10]=0x00;
	buffer[11]=0xFF;
	len=12;
	while(1) {
		sendto(sockfd, buffer, len, 0, (struct sockaddr *)&addr, addr_len);
		sleep(2); /*睡眠2秒*/
		printf("%s\n",buffer);
	}

	return 0;
}

// ----------------------------------------------------------------------------
// End of udp_client.c

