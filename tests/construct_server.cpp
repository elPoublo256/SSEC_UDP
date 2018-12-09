
#include "../include/udp_process.hpp"
//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MODULE construct_server
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
int main()
{

Process1 p;

p.start();

for(int i = 0; i < 5; i++)
{
std::this_thread::sleep_for(std::chrono::seconds(1));
//std::cout << "wait" << std::endl;
}
gsignal(SIGSTOP);

	
}
