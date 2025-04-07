cmake_minimum_required(VERSION 3.16)
project(pub1_3)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)  # geometry_msgs 의존성 추가

# 실행 파일 추가
add_executable(pub1_3 src/pub1_3.cpp)  # 실행 파일 이름 pub1_3으로 설정

# 타겟 링크
ament_target_dependencies(pub1_3 rclcpp geometry_msgs)  # geometry_msgs 의존성 추가

# 설치
install(TARGETS
  pub1_3  # 설치할 파일 이름 pub1_3으로 설정
  DESTINATION lib/${PROJECT_NAME})

ament_package()
