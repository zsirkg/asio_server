#include <iostream>
#include "server.h"
#include "connection.h"

Server::Server(int port)
    :acceptor_(io_service_, tcp::endpoint(tcp::v4(), port))
{
}

void Server::Start()
{
    StartAccept();
    io_service_.run();
}

void Server::StartAccept()
{
    boost::shared_ptr<Connection> new_connection(new Connection(io_service_));
    acceptor_.async_accept(new_connection->Socket(),
            boost::bind(&Server::HandleAccept, this, new_connection, boost::asio::placeholders::error));
}

void Server::HandleAccept(boost::shared_ptr<Connection> connection,
        const boost::system::error_code &ec)
{
    //acceptor_.is_open()
    if(!ec) {
        connection->Start();
    }
    StartAccept();
}
