#include <cstdlib>
#include <iostream>
#include <string>

#include "net/Client.h"

std::string read_args(int argc, char *argv[]) {
  std::string message = "Hello from client";
  if (argc == 1) {
    std::cout << "Usage: " << argv[0] << " <message>\n";
    exit(EXIT_FAILURE);
  }
  if (argc > 1) {
    message = argv[1];
  }
  return message;
}

int main(int argc, char *argv[]) {
  const int kPort = 8080;
  const std::string kServerAddress = "127.0.0.1";

  std::string message = read_args(argc, argv);

  tt::chat::client::Client client(kServerAddress, kPort);
  client.connect_to_server();
  client.send_and_receive_message(message);

  return 0;
}
