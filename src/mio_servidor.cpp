#include <ros/ros.h>
#include <using_markers/tres.h>
#include <visualization_msgs/Marker.h>

#include <cstdlib>

bool  add(using_markers::tres::Request  &req,
         using_markers::tres::Response &res)
{
  res.sum = req.c * req.a * req.b;
res.sum2 = 27;
res.sum3 = req.c * req.a * req.b;
  ROS_INFO("coordenadas: x=%ld, y=%ld, z=%ld", (long int)req.a, (long int)req.b, (long int)req.c);
  ROS_INFO("sending back response: [%ld,%ld,%ld]", (long int)res.sum, (long int)res.sum2, (long int)res.sum3);
  return true;

}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "mio_servidor");
  ros::NodeHandle n;
  ros::Rate r(2);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
 // if (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/my_frame";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "mio_servidor";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header



/*
  ros::ServiceClient client = n.serviceClient<using_markers::tres>("tres");
  using_markers::tres srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  srv.request.c = atoll(argv[3]);
  srv.request.signo = atoll(argv[4]);
*/

ros::ServiceServer service = n.advertiseService("tres", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();


  /*  marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0; */

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    marker_pub.publish(marker);

    // Cycle between different shapes
 /*   switch (shape)
    {
    case visualization_msgs::Marker::CUBE:
      shape = visualization_msgs::Marker::SPHERE;
      break;
    case visualization_msgs::Marker::SPHERE:
      shape = visualization_msgs::Marker::ARROW;
      break;
    case visualization_msgs::Marker::ARROW:
      shape = visualization_msgs::Marker::CYLINDER;
      break;
    case visualization_msgs::Marker::CYLINDER:
      shape = visualization_msgs::Marker::CUBE;
      break;
    } */
      ROS_INFO("Repito el bucle"); 
shape = visualization_msgs::Marker::CUBE;

    r.sleep();
  }
}
