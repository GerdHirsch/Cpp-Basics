cmake_minimum_required(VERSION 3.12)

project(LifecycleSession4)

add_executable(${PROJECT_NAME} src/main.cpp src/DemoCopyElision.cpp src/ParameterAndReturnExpressions.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
