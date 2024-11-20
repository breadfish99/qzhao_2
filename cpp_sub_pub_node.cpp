#include "ros/ros.h"
#include "std_msgs/String.h"

void topicCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received: [%s]", msg->data.c_str());
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "cpp_sub_pub_node");
    ros::NodeHandle nh;

    // 订阅话题
    ros::Subscriber sub = nh.subscribe("your_topic", 1000, topicCallback);

    // 发布话题
    ros::Publisher pub = nh.advertise<std_msgs::String>("new_topic", 1000);

    ros::Rate loop_rate(10);
    while (ros::ok()) {
        std_msgs::String msg;
        msg.data = "Hello from C++ publisher!";
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

