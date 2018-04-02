#include "ros/ros.h"
#include <using_markers/tres.h>

bool add(using_markers::tres::Request  &req,
         using_markers::tres::Response &res)
{
  res.sum = req.c * req.a * req.b;
  ROS_INFO("coordenadas: x=%ld, y=%ld, z=%ld", (long int)req.a, (long int)req.b, (long int)req.c);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "servidor");
  ros::NodeHandle n;

  ROS_INFO("He llegado aqui.");

  ros::ServiceServer service = n.advertiseService("tres", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();



  return 0;
}
