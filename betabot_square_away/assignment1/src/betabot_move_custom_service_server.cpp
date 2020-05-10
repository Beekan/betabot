#include "ros/ros.h"
#include "assignment1/BetabotCustomServiceMessage.h"
#include "geometry_msgs/Twist.h"
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf/tf.h>
#include <math.h>

class SquareMovement{
    private:
        double posX;
        double posY;
        double sideLength;
        int repNum;
        double yawRadian;
        int yawDegree;
        double pitch;
        double roll;
        double speed = 0.2;
        ros::Publisher velPub;
    public:
        SquareMovement();
        SquareMovement(ros::Publisher vel){velPub=vel;};

        void OdomCallback(const geometry_msgs::PoseWithCovarianceStampedConstPtr &msg){
            
            posX= msg->pose.pose.position.x;  // get the robot x pose from the odom topic
            posY = msg->pose.pose.position.y;  // get the robot y pose from the odom topic
            tf::Quaternion q(
            msg->pose.pose.orientation.x,
            msg->pose.pose.orientation.y,
            msg->pose.pose.orientation.z,
            msg->pose.pose.orientation.w);
            tf::Matrix3x3 m(q);
            m.getRPY(roll, pitch, yawRadian);
            yawDegree=(int)((yawRadian+M_PI)*(180/M_PI))%360;
            }

        bool moveForward(double &currentPos){

            double startPos=currentPos;
            geometry_msgs::Twist msg;
            while(ros::ok() && abs(currentPos-startPos)<sideLength){
                msg.linear.x=speed;
                velPub.publish(msg);
                //ROS_INFO("side x: %f",(double)(currentPos));
                ros::spinOnce();
            }
            msg.linear.x=0;
            velPub.publish(msg);
        }
        
        bool rotate90(){

            int startYaw=yawDegree;
            geometry_msgs::Twist msg;
            while( ros::ok() &&abs(yawDegree-startYaw)< 90){
                msg.angular.z=0.2;
                velPub.publish(msg);
                //ROS_INFO("angle: %d",(testyaw));
                ros::spinOnce();
            }
            msg.angular.z=0;
            velPub.publish(msg);
        }

        bool move(assignment1::BetabotCustomServiceMessage::Request &req,assignment1::BetabotCustomServiceMessage::Response &res){
    
            repNum=req.repetitions;
            sideLength=req.side;
        
            for(int i=0;i<repNum;i++){
                for(int s=0;s<2;s++){
                    moveForward(posX);
                    rotate90();
                    moveForward(posY);
                    rotate90();
                    if(!ros::ok()){
                        res.success=false;
                        return true;
                    }
               }
            }
            res.success=true;
            return true;
            }
};



int main(int argc, char** argv){
    ros::init(argc, argv, "betabot_move_custom_service_server"); // Initializes Node Name
    ros::NodeHandle nh;
    ros::Publisher velPub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    SquareMovement Move(velPub);
    ros::ServiceServer ros_service_server = nh.advertiseService("move_betabot_in_square_custom",&SquareMovement::move,&Move);
    ros::Subscriber pos= nh.subscribe<geometry_msgs::PoseWithCovarianceStamped>("/robot_pose_ekf/odom_combined",1,&SquareMovement::OdomCallback,&Move);
    ROS_INFO("ready srv server!");
    ros::spin();
    return 0;
}
