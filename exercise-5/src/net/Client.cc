#include "Client.h"
#include "chat-sockets.h"
#include "../utils.h"

#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

namespace tt::chat::client {

Client::Client(const std::string &server_ip, int port) {
  socket_fd_ = net::create_socket();
  create_server_address(server_ip, port);
}

Client::~Client() {
  close(socket_fd_);
}

void Client::create_server_address(const std::string &server_ip, int port) {
  server_address_ = net::create_address(port);
  auto err_code = inet_pton(AF_INET, server_ip.c_str(), &server_address_.sin_addr);
  check_error(err_code <= 0, "Invalid address/ Address not supported\n");
}

void Client::connect_to_server() {
  auto err_code = connect(socket_fd_, (sockaddr *)&server_address_, sizeof(server_address_));
  check_error(err_code < 0, "Connection Failed.\n");
}

void Client::send_and_receive_message(const std::string &message) {
  const int kBufferSize = 1024;
  char recv_buffer[kBufferSize] = {0};

  send(socket_fd_, message.c_str(), message.size(), 0);
  std::cout << "Sent: " << message << "\n";

  ssize_t read_size = read(socket_fd_, recv_buffer, kBufferSize);
  check_error(read_size < 0, "Read error.\n");
  if (read_size > 0) {
    std::cout << "Received: " << recv_buffer << "\n";
  } else if (read_size == 0) {
    std::cout << "Server closed connection.\n";
  }
}

}