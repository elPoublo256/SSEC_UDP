#include "../include/udp_process.hpp"
#include <cstdlib>
Massage::Massage()
{
 length_line = MIN_L + (std::rand() % (MAX_L - MIN_L));
 line.reserve(length_line);
 for(int i = 0; i < length_line; i++)
 {
   line.push_back('a' + (char)(std::rand() % 26));
 }
}


