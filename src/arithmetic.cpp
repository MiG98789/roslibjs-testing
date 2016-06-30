#include "robowebtools/robowebtools.hpp"

void countCallback(const std_msgs::UInt8::ConstPtr& msg)
{
	if(msg->data)
	{
		ROS_INFO("Reset count value.");
	}
}

int main(int argc, char **argv)
{  
	ros::init(argc, argv, "arithmetic_node");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe<std_msgs::UInt8>("/arithmetic/update/status", 100, &countCallback);
	ros::Publisher pub = n.advertise<std_msgs::Int64>("/arithmetic/update/value", 1);
	std_msgs::Int64 msg;

	int  temp = 0;

	while(ros::ok())
	{    
		ros::spinOnce();

		std::cout << "How much do you want to add? ";
		std::cin >> temp;

		msg.data = temp;
		pub.publish(msg);
	}

	return 0;
}
