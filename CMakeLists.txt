cmake_minimum_required(VERSION 2.8.3)

project(ssc_udp)

SET(CMAKE_CXX_STANDART 14)
SET(COMPILE_OPTIONS -Wpedantic -Wall -Wextra)
add_library(udp_proc ./include/udp_process.hpp
	./src/udp_process.cpp)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(test_rand_str ./tests/rand_str.cpp)
target_link_libraries(test_rand_str ${Boost_LIBRARIES} udp_proc)
#add_executable(ssc_udp main.cpp)
