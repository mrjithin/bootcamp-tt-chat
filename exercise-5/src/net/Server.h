#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

namespace tt::chat::server {

class Server {
public:
  Server(int port);
  ~Server();

  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

  void start();

private:
  int port_;
  int socket_fd_;
  sockaddr_in address_;

  void setup_socket();
  void bind_and_listen();
  void handle_connections();
  void handle_client(int client_socket);
};

} // namespace tt::chat::server

#endif
