cmake_minimum_required(VERSION 3.24)
project(CLI_CPP)

find_package(TBB REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp point3.cpp point3.h)

target_link_libraries(${PROJECT_NAME} PRIVATE TBB::tbb)
