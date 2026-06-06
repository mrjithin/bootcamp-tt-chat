#include "Server.h"
#include "chat-sockets.h"
#include "../utils.h"

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>

namespace tt::chat::server {

Server::Server(int port) : port_(port) {
  setup_socket();
}

Server::~Server() {
  close(socket_fd_);
}

void Server::setup_socket() {
  socket_fd_ = net::create_socket();
  int opt = 1;
  auto err_code = setsockopt(socket_fd_, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                             &opt, sizeof(opt));
  check_error(err_code < 0, "setsockopt() error\n");

  address_ = net::create_address(port_);
  address_.sin_addr.s_addr = INADDR_ANY;
}

void Server::bind_and_listen() {
  auto err_code = bind(socket_fd_, (sockaddr *)&address_, sizeof(address_));
  check_error(err_code < 0, "bind failed\n");

  err_code = listen(socket_fd_, 3);
  check_error(err_code < 0, "listen failed\n");
}

void Server::handle_client(int client_socket) {
  const int kBufferSize = 1024;
  char buffer[kBufferSize] = {0};
  ssize_t read_size = read(client_socket, buffer, kBufferSize);

  check_error(read_size < 0,
              "Read error on client socket " + std::to_string(client_socket));
  if (read_size > 0) {
    std::cout << "Received:" << buffer << "\n";
    send(client_socket, buffer, read_size, 0);
    std::cout << "Echo message sent\n";
  } else if (read_size == 0) {
    std::cout << "Client disconnected.\n";
  } else {
    std::cerr << "Read error on client socket " << client_socket << "\n";
  }
  close(client_socket);
}

void Server::handle_connections() {
  socklen_t address_size = sizeof(address_);

  while (true) {
    int accepted_socket = accept(socket_fd_, (sockaddr *)&address_, &address_size);
    check_error(accepted_socket < 0, "Accept error n ");
    handle_client(accepted_socket);
  }
}

void Server::start() {
  bind_and_listen();
  std::cout << "Server listening on port " << port_ << "\n";
  handle_connections();
}

}
