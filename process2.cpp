#include "include/udp_process.hpp"
#include <iostream>

int main(int argc, char argv[])
{
    if(argc <=2)
    {
        std::cerr<<"set interval in ms and serveice name "<<
                   "of server as arguments" << std::endl;
        return 1;
    }
auto interval = std::stoi(std::string(argv[1]));
Process2 client(interval, argv[2]);
client.start();

    return 0;
}

