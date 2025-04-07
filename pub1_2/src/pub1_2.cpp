#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include <iostream>

class PublisherNode : public rclcpp::Node
{
public:
    PublisherNode() : Node("publisher_node")
    {
        // Publisher 생성
        publisher_ = this->create_publisher<geometry_msgs::msg::Vector3>("topic_pub1", 10);
        
        // 타이머 설정: 1초마다 퍼블리시
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            [this]() {
                // 사용자로부터 실수값 3개 입력 받기
                float x, y, z;
                std::cout << "Enter 3 float values (x, y, z): ";
                std::cin >> x >> y >> z;
                
                auto message = geometry_msgs::msg::Vector3();
                message.x = x;
                message.y = y;
                message.z = z;
                
                RCLCPP_INFO(this->get_logger(), "Publishing: x=%f, y=%f, z=%f", message.x, message.y, message.z);
                
                // 퍼블리시
                publisher_->publish(message);
            });
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);  // ROS2 초기화
    rclcpp::spin(std::make_shared<PublisherNode>());  // PublisherNode 실행
    rclcpp::shutdown();  // 종료
    return 0;
}

