#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <termios.h>
#include <unistd.h>
#include <iostream>

class TeleopTurtle : public rclcpp::Node
{
public:
    TeleopTurtle() : Node("teleop_turtle")
    {
        // Publisher 생성
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

        // 타이머 설정: 0.1초마다 키 입력 처리
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            [this]() {
                char key = getKey();
                geometry_msgs::msg::Twist msg;

                // 키에 따라 Turtle 이동 제어
                switch (key)
                {
                    case 'f':  // 전진
                        msg.linear.x = 1.0;
                        msg.angular.z = 0.0;
                        break;
                    case 'b':  // 후진
                        msg.linear.x = -1.0;
                        msg.angular.z = 0.0;
                        break;
                    case 'l':  // 좌회전
                        msg.linear.x = 0.0;
                        msg.angular.z = 1.0;
                        break;
                    case 'r':  // 우회전
                        msg.linear.x = 0.0;
                        msg.angular.z = -1.0;
                        break;
                    default:
                        msg.linear.x = 0.0;
                        msg.angular.z = 0.0;
                        break;
                }

                // 메시지 발행
                publisher_->publish(msg);
            });
    }

private:
    // 키보드 입력을 받는 함수
    char getKey()
    {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);  // 개별 키 입력 받기
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);  // ROS2 초기화
    rclcpp::spin(std::make_shared<TeleopTurtle>());  // TeleopTurtle 노드 실행
    rclcpp::shutdown();  // 종료
    return 0;
}

