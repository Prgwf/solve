cmake_minimum_required(VERSION 2.8.4)
project(Goodbye2017)

add_executable(output output/main.cpp output/main.cpp testrunner/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp" )

ADD_DEFINITIONS(-std=c++11)

add_executable(test ${TASKS} ${HEADERS})
