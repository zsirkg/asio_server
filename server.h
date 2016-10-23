#ifndef _SERVER_H_
#define _SERVER_H_
#include <boost/asio.hpp>
#include "connection.h"

using boost::asio::ip::tcp;

class Server {
    public:
        Server(int port);
        void Start();
    private:
        void StartAccept();
        void HandleAccept(boost::shared_ptr<Connection> new_connection,
                const boost::system::error_code &ec);
        boost::asio::io_service io_service_;
        tcp::acceptor acceptor_;
};
#endif
