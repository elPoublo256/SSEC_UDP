#pragma once
//#include </usr/include/boost/asio.hpp>
///this is RAII class which using udp sockets
#define UDP_PORT 23456
#define MAX_L 20
#define MIN_L 5
#include <string>
#include <fstream>


class Massage
{
public:
	std::size_t length_line;
	std::string line;
    Massage();
    auto begin(){return line.begin();}
    auto end() {return line.end();}



};

class Process1
{
};

class Process2
{
public:
    unsigned int time_interval;
    std::ofstream fileStream;
    std::string mass;
    //void print_mass;

};
