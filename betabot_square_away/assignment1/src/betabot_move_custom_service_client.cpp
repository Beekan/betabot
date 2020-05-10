#include "ros/ros.h"
#include "assignment1/BetabotCustomServiceMessage.h"
#include <cstdlib>
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "betabot_move_custom_service_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<assignment1::BetabotCustomServiceMessage>("move_betabot_in_square_custom");
  assignment1::BetabotCustomServiceMessage srv;
  srv.request.repetitions = atoll(argv[1]);
  srv.request.side = atoll(argv[2]);
  if (client.call(srv))
  {
    //ROS_INFO("success: %ld", (bool)srv.response.success);
    ROS_INFO("side: %ld",(int)srv.request.side);
    ROS_INFO("repititions: %ld",(int) srv.request.repetitions);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}