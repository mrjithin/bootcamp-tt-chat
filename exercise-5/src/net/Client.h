#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>
#include <string>

namespace tt::chat::client {

class Client {
public:
  Client(const std::string &server_ip, int port);
  ~Client();

  Client(const Client &) = delete;
  Client &operator=(const Client &) = delete;

  void connect_to_server();
  void send_and_receive_message(const std::string &message);

private:
  int socket_fd_;
  sockaddr_in server_address_;

  void create_server_address(const std::string &server_ip, int port);
};

}

#endif