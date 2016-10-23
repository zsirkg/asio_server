#include "connection.h"

using namespace std;

Connection::Connection(boost::asio::io_service& io_service)
    :socket_(io_service)
{
}

void Connection::Start()
{
    socket_.async_read_some(boost::asio::buffer(&msg_buf_, sizeof(msg_buf_)),
            boost::bind(&Connection::HandleRead, shared_from_this(), _1, _2));
}

tcp::socket& Connection::Socket()
{
    return socket_;
}

void Connection::HandleRead(const boost::system::error_code& ec,
        size_t bytes_transferred)
{
    if(!ec) {
        socket_.async_write_some(boost::asio::buffer(&msg_buf_, bytes_transferred),
                boost::bind(&Connection::HandleWrite, shared_from_this(), _1));
    }
}

void Connection::HandleWrite(const boost::system::error_code& ec)
{
    if(!ec) {
        socket_.async_read_some(boost::asio::buffer(&msg_buf_, sizeof(msg_buf_)),
                boost::bind(&Connection::HandleRead, shared_from_this(), _1, _2));
    }
}
