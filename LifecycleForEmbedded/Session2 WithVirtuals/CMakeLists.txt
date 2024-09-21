cmake_minimum_required(VERSION 3.12)

project(LifecycleEmbeddedSession2)

add_executable(${PROJECT_NAME} src/main.cpp src/Demos.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
