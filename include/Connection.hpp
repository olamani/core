#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>

namespace olamani {

struct Socket {
    int socketfd;
    struct sockaddr_in server;
}

class Connection {
public:
    Connection(std::string host, int port);
    ~Connection();
    bool connect();
    void disconnect();
    bool send(std::string message);
    std::string receive();
private:
    std::string host;
    int port;
    Socket socket;
    bool open;
} // class Connection

} // namespace olamani

#endif // CONNECTION_HPP
