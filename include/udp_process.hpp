#pragma once
#include <boost/asio.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


#define UDP_PORT 23456
#define MAX_L 20
#define MIN_L 5
#include <string>
#include <fstream>
#include <memory>
#include <boost/array.hpp>
using namespace boost::asio;
class Massage
{
public:
	std::size_t length_line;
	std::string line;
    Massage();
    auto begin(){return line.begin();}
    auto end() {return line.end();}



};
class UDP_Process
{
public:
   const static std::string service_name;// = "ssc_udp_service";
    virtual void start_working();
protected:

   std::unique_ptr<io_service> io;
   ip::udp::endpoint ep;//copyble, heve defult constructors
   std::unique_ptr<ip::udp::socket> socket;
   //TODO use boost log lib
    virtual std::basic_ostream<char>& logger();
    virtual ~UDP_Process(){}
   virtual void start(){}

};
///wait packet from client
/// it open UDP socket with UDP_PORT
/// and wait strings from server
class Process1 : public UDP_Process
{
public:
    std::size_t allMessSize;
    Process1(const std::string& hostname = std::string("0.0.0.0"));
    std::string buf_str;
    std::unique_ptr<ip::udp::resolver> resolver;
    std::unique_ptr<ip::udp::resolver::query> query;
    std::unique_ptr<deadline_timer> timer;
    ~Process1() override;
    void start() override;

     static void hendler(const boost::system::error_code& err,
                  std::size_t num_bytes)
     {}

};
///print random string with char [a-z]
/// send string with length = [5-20] bytes
/// in loop with interval seted in emit constructor
class Process2 : public UDP_Process
{
public:
    Process2(const unsigned int& interval);
    unsigned int time_interval;
    std::ofstream fileStream;
    std::string mass;


    void send_mess();
};
