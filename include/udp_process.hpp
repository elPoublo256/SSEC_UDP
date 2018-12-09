#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <array>

#define UDP_PORT 23456
#define MAX_L 20
#define MIN_L 5
#define MAX_FILE_SIZE 256
#include <string>
#include <fstream>
#include <memory>
#include <boost/array.hpp>
using namespace boost::asio;



class UDP_Process
{
public:
   const static std::string service_name;// = "ssc_udp_service";
    virtual void start_working();
protected:

   io_service io;
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
    std::size_t size_file;
    Process1();
    std::array<char,MAX_L> buf;
    std::ofstream result;


    std::unique_ptr<ip::udp::resolver::query> query;

    ~Process1() override;
    void start() override;
    void stop();
    void hendler(const boost::system::error_code& err,
                  std::size_t num_bytes);

};
///print random string with char [a-z]
/// send string with length = [5-20] bytes
/// in loop with interval seted in emit constructor
class Process2 : public UDP_Process
{
public:
    unsigned int _interval;
    typedef ip::udp::resolver::query b_query;
    deadline_timer _timer;
    ip::udp::resolver resolver;
    std::unique_ptr<b_query> query;
    Process2(const unsigned int& interval, char* server_name );
    unsigned int time_interval;
    void start() override;
    std::string buf_for_sebd;
    void send_mess(const boost::system::error_code& error,
                   boost::asio::deadline_timer* _timer);
    ~Process2() override;
};
