cmake_minimum_required(VERSION 3.12)

project(LifecycleEmbeddedSession4)

add_executable(${PROJECT_NAME} src/main.cpp )
target_include_directories(${PROJECT_NAME} PUBLIC include)
