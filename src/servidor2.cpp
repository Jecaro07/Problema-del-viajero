#include "ros/ros.h"
#include <using_markers/tres.h>

bool  add(using_markers::tres::Request  &req,
         using_markers::tres::Response &res)
{
  res.sum = req.c * req.a * req.b;
res.sum2 = req.b;
res.sum3 = req.c * req.a * req.b;
  ROS_INFO("coordenadas: x=%ld, y=%ld, z=%ld", (long int)req.a, (long int)req.b, (long int)req.c);
  ROS_INFO("sending back response: [%ld,%ld,%ld]", (long int)res.sum, (long int)res.sum2, (long int)res.sum3);
  return true;

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "servidor");
  ros::NodeHandle n;

while (ros::ok()){
  ros::ServiceServer service = n.advertiseService("tres", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

}

  return 0;
}
