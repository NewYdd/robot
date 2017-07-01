#include <communication/serialPort.h>
#include <communication/display.h>
#include <boost/asio.hpp>                  //包含boost库函数
#include <boost/bind.hpp>
#include <string>
#include <ros/ros.h>
#include <fcntl.h>

using namespace std;
using namespace boost::asio;           //定义一个命名空间，用于后面的读写操作'''


#define PORTNAME   "/dev/ttyUSB1"
#define  BAUD           9600
#define  WAIT_TIME   0.2

 char ask[ ]={ 0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B } ;


unsigned int getHight( unsigned char *height )
{
 	unsigned char *p = height;
 	unsigned int intHeight = 0;
 	intHeight = (int)*(p+3)*256 + (int)*(p+4);
 	intHeight = intHeight *1000 + (int)*(p+5)*256+ (int)*(p+6);

 	return  intHeight ;
} 	


  

int main(int argc ,char **argv)
{
	ros::init(argc,argv,"getHight");
	ros::NodeHandle nh;
	io_service iosev;
	 serial_port sp(iosev,PORTNAME );         //定义传输的串口


	 sp.set_option(serial_port::baud_rate(9600));  
	  sp.set_option(serial_port::flow_control( serial_port::flow_control::none));
	 sp.set_option(serial_port::parity(serial_port::parity::none));
	 sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));
	 sp.set_option(serial_port::character_size(8));
 	 
	
	while(ros::ok())
	{
		int send=write(sp, buffer(ask, 8));
		printf("ask for height  %d \n",send);
                            
		char buff[9];
		
		int readByte=0;
		readByte=read (sp,buffer(buff));
		//async_read( sp, buffer(buff), boost::bind( &handle_read, buff, 9));
		//time out


		unsigned char buff_temp[9];
		for(int i=0;i<9;i++)
		{
			buff_temp[i]=buff[i];

		}
	
		HexDump(buff,9,0);
		
		int height = getHight(buff_temp);
		printf("get the height %d\n", height );
		printf("\n");

  		ros::Duration(WAIT_TIME).sleep();
  		
		//pub the state
 	}
 	  iosev.run(); 
 	    return 0;
}