#include <communication/serialPort.h>
#include <communication/display.h>
#include <ros/ros.h>

#define PORTNAME   "/dev/ttyUSB0"
#define  BAUD             9600
#define  WAIT_TIME   1


const unsigned char ask[ ]={ 0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B } ;

int main(int argc ,char **argv)
{
	ros::init(argc,argv,"getHight");
	ros::NodeHandle nh;
	SerialPort  myserial(PORTNAME);
	if( myserial.openPort()  != -1)
		printf("open ok\n");

	myserial.setPort(BAUD,8,1,'N');

	//ask for height

	int lenth = sizeof(ask) / sizeof (char);
	while(ros::ok())
	{
		write(myserial.fd , ask, lenth);
		printf("ask for height\n");

		ros::Duration(WAIT_TIME).sleep();
		char  buff[1024];
		int    Len=0;
		int readByte=0;
		readByte=read(myserial.fd , buff , Len);
		printf("get the height\n\n");
	
  		HexDump(buff,readByte,0);
		//pub the state
 	}
	return 0;
}