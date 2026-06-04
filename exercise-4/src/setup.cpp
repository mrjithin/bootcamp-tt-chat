#include "setup.h"

int create_socket() {
  int my_sock;
  my_sock = socket(AF_INET, SOCK_STREAM, 0);
  check_error(my_sock < 0, "Socket creation error\n");
  return my_sock;
}

sockaddr_in create_address(int port) {
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  return address;
}

sockaddr_in create_address(const std::string &server_ip, int port) {
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = htons(port);

  // Convert the server IP address to a binary format
  auto err_code = inet_pton(AF_INET, server_ip.c_str(), &address.sin_addr);
  check_error(err_code <= 0, "Invalid address/ Address not supported.\n");
  return address;
}