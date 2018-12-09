cmake_minimum_required(VERSION 2.8.3)

project(ssc_udp)

SET(CMAKE_CXX_STANDART 14)
SET(COMPILE_OPTIONS -Wpedantic -Wall -Wextra)
add_library(udp_proc ./include/udp_process.hpp
	./src/udp_process.cpp)
find_package(Boost COMPONENTS unit_test_framework
thread
date_time
regex
system
	REQUIRED)

  find_package(Threads)
  target_link_libraries(udp_proc ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
add_executable(test_rand_str ./tests/rand_str.cpp)

#add_executable(asinc_timer ./tests/asinc_timer_boost_example.cpp)
# this file copied from boost doc from 
#https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/tutorial/tuttimer3/src.html
#target_link_libraries(asinc_timer ${Boost_LIBRARIES})


target_link_libraries(test_rand_str udp_proc)
#add_executable(ssc_udp main.cpp)
