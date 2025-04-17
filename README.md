1. 1번을 수정하여 문자열 대신에 정수값을 0으로 초기화하고 1씩 증가시키면서
  퍼블리시하는 패키지 pub1-1를 작성하시오.
+ 토픽 메시지 인터페이스는 std_msgs/msg/Int32을 사용할 것
+ 소스파일작성시 헤더파일명과 클래스명을 수정해야함
![스크린샷 2025-04-07 103113](https://github.com/user-attachments/assets/9e15221c-7683-49c9-8424-2c76e68c81cf)

2. 1번을 수정하여 키보드로부터 실수값 3개를 입력 받아 퍼블리시하는 패키지 pub1-2를 작성하시오.
+ 토픽 메시지 인터페이스는 geometry_msgs/msg/Vector3을 사용
+ 패키지 생성시 의존패키지에서 std_msgs->geometry_msgs으로 수정해야함
+ 소스파일작성시 헤더파일명과 클래스명을 수정해야함(15페이지 참고)
+ CMakeLists.txt의 add_executables 명령에서 의존 패키지를 std_msgs->geometry_msgs으로 수정해야함
![image](https://github.com/user-attachments/assets/811d89e0-bbed-4fc0-98ee-633f4aca0703)

3.Turtlesim 패키지의 teleop_turtle 노드를 대신하는 패키지 pub1-3를 작성하라.
+ 키보드 입력시 /turtle1/cmd_vel 토픽을 발행하도록 할 것
+ f-> 전진, b->후진, l->좌회전, r->우회전
+ 메시지 인터페이스는 geometry_msgs/msg/Twist를 사용할 것
+ 패키지 생성시 의존패키지에서 std_msgs -> geometry_msgs으로 변경
+ 소스파일작성시 헤더파일명과 클래스명을 수정해야함(15페이지 참고)
+ CMakeLists.txt의 add_executables 명령에서 의존 패키지를 std_msgs에서 geometry_msgs으로 변경
+ turtlesim(subscriber 역할수행) 노드를 실행하고 테스트 할 것 
 ![image](https://github.com/user-attachments/assets/cc223e7c-43f1-40cf-9760-4a51000d0cdf)
