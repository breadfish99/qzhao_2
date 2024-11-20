
import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo("Received: %s", data.data)

def subscriber_publisher():
    rospy.init_node('python_sub_pub_node', anonymous=True)

    # 订阅话题
    rospy.Subscriber('your_topic', String, callback)

    # 发布话题
    pub = rospy.Publisher('new_topic', String, queue_size=10)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        msg = String()
        msg.data = "Hello from Python publisher!"
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        subscriber_publisher()
    except rospy.ROSInterruptException:
        pass

