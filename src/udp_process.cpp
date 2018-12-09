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

void UDP_Process::start_working(){}
const std::string UDP_Process::service_name = "ssc_udp_service";

std::basic_ostream<char>& UDP_Process::logger()
{
    return std::cerr;
}

Process1::Process1(const std::string& hostname)
{
    io = std::make_unique<io_service>();
    resolver = std::make_unique<boost::asio::ip::udp::resolver>(*io);
    socket = std::make_unique<ip::udp::socket>(*io);
    query = std::make_unique<ip::udp::resolver::query>
            (ip::udp::v4(), hostname, this->service_name);
    ep = *(resolver->resolve(*query));
}

void Process1::start()
{
    try
    {
        auto _hendler = [](const boost::system::error_code& err,
                std::size_t num_bytes){};
        auto boost_buf = boost::asio::buffer(buf_str);
    }
    catch(std::exception &e)
    {
        this->logger() << e.what() << std::endl;
    }
}



Process1::~Process1()
{

}

Process2::Process2(const unsigned int &interval)
{

}
