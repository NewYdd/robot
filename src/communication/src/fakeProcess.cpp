/*模拟主控
调用plc服务
调用move服务
提供状态信息
*/
#include "ros/ros.h"
#include <communication/sendCmd.h>
#include <communication/state.h>
#include <cstdlib>
using namespace std;
int main(int argc, char **argv)
{
      ros::init(argc, argv, "fake_processor");
      

      ros::NodeHandle n;
      ros::ServiceClient client = n.serviceClient<communication::sendCmd>("send_plc_cmd");
      ros::ServiceClient client1 = n.serviceClient<communication::sendCmd>("send_move_cmd");

      ros::Publisher pub=n.advertise<communication::state>("processor/state",10);

      communication::sendCmd srv;
      communication::state  msg;

      char cmd_type=0x30;
      string p="";
      char temp=0x31;
      p+=temp;
      temp=0x00;
      p+=temp;

      srv.request.type+=cmd_type;
      srv.request. data+=p;

      ros::Rate rate(2);
      if(strcmp(argv[1],"move")==0)
      {     
            printf("move serve\n");
          if (client1.call(srv)&&srv.response.receive)
            {
              ROS_INFO("sucess");
            }
            else    
            {
              ROS_ERROR("Failed ");
              return 1;
            }
    }

    else if(strcmp(argv[1],"pub")==0)
    {

        while (ros::ok())
        {    printf("pub state to shangweiji\n");
                msg.data="hello";
                pub.publish(msg);
                rate.sleep();
            }

    }

    else
    {
        printf("plc serve\n");
          if (client.call(srv)&&srv.response.receive)
            {
              ROS_INFO("sucess");
            }
            else
            {
              ROS_ERROR("Failed ");
              return 1;
            }
    }   
    return 0;
}
