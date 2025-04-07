#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class PublisherNode : public rclcpp::Node
{
public:
    PublisherNode() : Node("publisher_node")
    {
        // Publisher 생성, 10은 큐의 크기
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("topic_pub1", 10);

        // 1초마다 퍼블리시하도록 설정
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            [this]() {
                auto message = std_msgs::msg::Int32();
                message.data = counter_;  // counter 값 증가시켜서 퍼블리시
                RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
                publisher_->publish(message);
                counter_++;  // 카운터 값 1씩 증가
            });
    }

private:
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_ = 0;  // 초기값 설정
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);  // ROS2 초기화
    rclcpp::spin(std::make_shared<PublisherNode>());  // PublisherNode 실행
    rclcpp::shutdown();  // 종료
    return 0;
}
