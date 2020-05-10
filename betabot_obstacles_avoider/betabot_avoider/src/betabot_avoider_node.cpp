#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf/tf.h>
#include <math.h>

class RandomMover{
    private:
        double speed = 0.2;
        double proximity;
        double proximityleft;
        double proximityright;
        double threshold=0.3;
        ros::NodeHandle nh_;
        ros::Publisher velPub_;
        ros::Subscriber laserData_;
        int areas=0;
    public:
        RandomMover(){
            velPub_=nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
            laserData_=nh_.subscribe<sensor_msgs::LaserScan>("/scan",10,&RandomMover::LaserScan,this);
        }


        void LaserScan(const sensor_msgs::LaserScanConstPtr &msg){
            // proximity=msg->ranges[0];
            // proximityleft=msg->ranges[1500];
            // proximityright=msg->ranges[1150];
            areas=0;
            for(int i=0;i<500;i++){
                if(msg->ranges[i]>threshold && msg->ranges[2000-i]>threshold){
                    areas++;
                }
            }
            

        }


        void move(){
            geometry_msgs::Twist msg;
            while(ros::ok()){
                if(areas>498){
                    msg.linear.x=speed;
                    msg.angular.z=0;
                }
                else
                {
                    msg.linear.x=0;
                    msg.angular.z=1;
                }
                velPub_.publish(msg);
                ros::spinOnce();
            }
            
        }
};

int main(int argc, char** argv){
    ros::init(argc, argv, "betabot_avoider"); // Initializes Node Name
    RandomMover Mover;
    Mover.move();
    ros::spin();
    return 0;
}
