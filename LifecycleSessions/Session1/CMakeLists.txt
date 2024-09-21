cmake_minimum_required(VERSION 3.12)

project(LifecycleSession1)

add_executable(${PROJECT_NAME} src/main.cpp src/exercises.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
