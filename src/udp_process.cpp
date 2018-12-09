#include "../include/udp_process.hpp"
#include <cstdlib>



auto get_random_line()
{
    std::string line;

   auto length_line = MIN_L + (std::rand() % (MAX_L - MIN_L));
    line.reserve(length_line);
    for(int i = 0; i < length_line; i++)
    {
      line.push_back('a' + (char)(std::rand() % 26));
    }
    return std::move(line);
}

void UDP_Process::start_working(){}
const std::string UDP_Process::service_name = "ssc_udp_service";

std::basic_ostream<char>& UDP_Process::logger()
{
    return std::cerr;
}

Process1::Process1() : result("sended_lines.txt"), size_file(0)
{
    ep = ip::udp::endpoint(ip::udp::v4(), UDP_PORT);
    socket = std::make_unique<ip::udp::socket>(io, ep);
    start();

}

void Process1::start()
{
    try
    {
        socket->async_receive_from(
                    boost::asio::buffer(buf),
                    ep,
                    boost::bind(& Process1::hendler, this,
                                boost::asio::placeholders::error,
                                boost::asio::placeholders::bytes_transferred));

        logger() << "starting server" << std::endl;
        io.run();

    }
    catch(std::exception &e)
    {
       this->logger() << e.what() << std::endl;
    }
}

void Process1::hendler(const boost::system::error_code &err, std::size_t num_bytes)
{
  if(this->size_file < MAX_FILE_SIZE)
  {
    if(err)
    {
        logger() << "ERROR" <<err.message() << std::endl;
        return;
    }
    else
    {
        result.write(buf.data(),num_bytes);
        this->size_file += num_bytes;
    }
  }
}

Process1::~Process1()
{
io.stop();
if(socket->is_open())
   socket->close();
}

Process2::Process2(const unsigned int &interval,  char* servername) :
    _timer(io, boost::posix_time::millisec(interval)),
    resolver(io), _interval(interval)
{
    socket = std::make_unique<ip::udp::socket>(io);
    query = std::make_unique<Process2::b_query>(ip::udp::v4(),servername );
    ep = *(resolver.resolve(*query));
}



void Process2::start()
{
  socket->open(ip::udp::v4());
  _timer.async_wait(boost::bind(send_mess,
               boost::asio::placeholders::error, &_timer));
}
Process2::~Process2()
{
    io.stop();
    if(socket->is_open())
      socket->close();
}

void Process2::send_mess(const boost::system::error_code& error, boost::asio::deadline_timer* timer)
{
    if(!error)
    {
    buf_for_sebd = get_random_line();
    socket->send_to(boost::asio::buffer(buf_for_sebd), ep);
    timer->expires_at(timer->expires_at() + boost::posix_time::millisec(_interval));

    timer->async_wait(boost::bind(send_mess,
          boost::asio::placeholders::error,
                                  timer));
    }
}
