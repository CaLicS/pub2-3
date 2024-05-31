// #include "rclcpp/rclcpp.hpp"
// #include "geometry_msgs/msg/vector3.hpp"
// #include "geometry_msgs/msg/twist.hpp"
// #include <memory>
// #include <chrono>
// #include <functional>
// using namespace std::chrono_literals;

// void callback(rclcpp::Node::SharedPtr node, 
// rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub)
// {
//     geometry_msgs::msg::Twist message;
//     message.linear.x = 1;
//     //message.linear.y = 1;
//     message.angular.x = 1;
//     message.angular.z = 1;
//     pub->publish(message);
//     RCLCPP_INFO(node->get_logger(), "msg sent");
// }

// int main(int argc, char* argv[])
// {
//     rclcpp::init(argc, argv);
//     auto node = std::make_shared<rclcpp::Node>("pub2_3");
//     auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
//     auto pub = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", qos_profile);
//     std::function<void()> fn = std::bind(callback, node, pub);
//     auto timer = node->create_wall_timer(100ms, fn);
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }


#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <memory>
#include <chrono>
#include <functional>
using namespace std::chrono_literals;

void callback(rclcpp::Node::SharedPtr node, 
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub)
{
    auto message = geometry_msgs::msg::Twist();
    message.linear.x = 1;
    message.angular.z = 1;
   
    RCLCPP_INFO(node->get_logger(), "message");
    pub->publish(message);
}
int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("pub2_3");
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    auto pub = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", qos_profile);
    std::function<void()> fn = std::bind(callback, node, pub);
    auto timer = node->create_wall_timer(1000ms, fn);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
