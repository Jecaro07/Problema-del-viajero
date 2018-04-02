#include <ros/ros.h>
#include <using_markers/tres.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cliente");
  if (argc != 5)
  {
    ROS_INFO("usage: cliente X Y Z");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<using_markers::tres>("tres");
  using_markers::tres srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  srv.request.c = atoll(argv[3]);
  srv.request.signo = atoll(argv[4]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service Tres");
    return 1;
  }

  return 0;
}
