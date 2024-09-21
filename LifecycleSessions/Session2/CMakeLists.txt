cmake_minimum_required(VERSION 3.12)

project(LifecycleSession2)

add_executable(${PROJECT_NAME} src/main.cpp src/Lifecycle.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
