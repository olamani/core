#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "Connection.hpp"

namespace olamani {

Connection::Connection(std::string host, int port) {
    this->host = host;
    this->port = port;
    open = false;
}

Connection::~Connection() {
    if (open) {
        disconnect();
    }
}

bool Connection::connect() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_0;
    struct in_addr *addr_ptr;
    char* host = (this->host).c_str();
    if (inet_addr(host) == INADDR_NONE) {
        host_0 = (struct hostent *) gethostbyname(host);
        if (host_0 == 0) {
            std::cerr << "Connection:connect -> can not get host" << std::endl;
            return false;
        } else {
            addr_ptr = (struct in_addr *)(*host_0->h_addr_list);
            host = inet_ntoa(*addr_ptr);
        }
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Connect::connect -> cannot open socket" << std::endl;
        return false;
    }
    bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(0);
	sock.server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		std::cerr << "Connect:connect -> cannot bind host" << std::endl; //Error: can not bind host
		return false;
	}
	sock.socketfd = sockfd;
	bzero(&sock.server, sizeof(sock.server));
	sock.server.sin_family = AF_INET;
	sock.server.sin_port = htons(port);
	sock.server.sin_addr.s_addr = inet_addr(host);
    open = true;
	return true;
}

void Connection::disconnect() {
	shutdown(sock.socketfd, SHUT_RDWR);
	close(sock.socketfd);
    open = false;
}

bool Connection::send(std::string message) {
	int size = message.size() + 1;
	if (sendto(sock.socketfd, message.c_str(), size, 0, (struct sockaddr *)&sock.server, sizeof(sock.server)) < 0) {
		std::cerr << "Connect::send -> error sending message " << message << std::endl;
		return false;
	}
	return true;
}

std::string Connection::receive() {
	char message[4096];
	socklen_t servlen;
	struct sockaddr_in serv_addr;
	servlen = sizeof(serv_addr);
	if (recvfrom(sock.socketfd, message, 4096, 0, (struct sockaddr *)&serv_addr, &servlen) < 0) {
		std::cerr << "Connect::receive -> error reading message" << std::endl;
		return "(error socket_failed)";
	} else {
		if (sock.server.sin_port != serv_addr.sin_port) {
			sock.server.sin_port = serv_addr.sin_port;
		}
		return std::string(message);
	}
}

} // namespace olamani
