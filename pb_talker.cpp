#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include "ros/ros.h"
#include "publish_info.pb.h"
int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  ros::NodeHandle n;

  ros::Publisher pub =
      n.advertise<mylcj::sample::PublishInfo>("/Lcj", 1000);

  ros::Rate loop_rate(10);
  
  mylcj::sample::PublishInfo proto_msg_info;
  proto_msg_info.set_name("lcj");
  proto_msg_info.set_message_type("test_message");
  proto_msg_info.set_publish_msg("lcj is making protocal buf");

  int count = 0;
  while (ros::ok()) {
    pub.publish(proto_msg_info);
    std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
