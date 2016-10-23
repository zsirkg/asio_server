#ifndef _CONNECTION_H_
#define _CONNECTION_H_
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

class Connection
    :public boost::enable_shared_from_this<Connection>
{
    public:
        Connection(boost::asio::io_service& io_service);

        // get socket
        tcp::socket& Socket();

        // start receive data from connection.
        void Start();
    private:
        void HandleRead(const boost::system::error_code& ec/*error*/,
                size_t data_size/*bytes_transferred*/);
        void HandleWrite(const boost::system::error_code& ec);
        tcp::socket socket_;
        char msg_buf_[1024];
};


#endif
