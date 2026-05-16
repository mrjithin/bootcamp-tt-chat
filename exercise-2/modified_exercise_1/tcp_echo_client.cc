#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

const int kBufferSize = 1024;
const std::string kServerAddress = "127.0.0.1";
const int kPort = 8080;
const std::string kDefaultMessage = "Hello from client";

// Determine the message to send based on command line arguments
std::string messageToSend(int argc, char *argv[]) {
  std::string message = kDefaultMessage; // Default message
  if (argc > 1) {
    message = argv[1];
  }
  return message;
}

// Create a socket and return its file descriptor
auto createSocket(auto family = AF_INET, auto type = SOCK_STREAM, auto protocol = 0) {
  int my_sock = socket(family, type, protocol);
  if (my_sock < 0) {
    std::cerr << "Socket creation error\n";
    return -1;
  }
  return my_sock;
}

// Set up the socket address structure
auto socketAddressSetup(auto &address, auto family){
  address.sin_family = family;
  address.sin_port = htons(kPort);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(family, kServerAddress.c_str(), &address.sin_addr) <= 0) {
    std::cerr << "Invalid address/ Address not supported\n";
    return -1;
  }
  return 0;
}

// Send a message to the server
auto sendMessage(int my_sock, const std::string &message) {
  send(my_sock, message.c_str(), message.size(), 0);
  std::cout << "Sent: " << message << "\n";
}

// Read a message from the server
auto readMessage(int my_sock, char *buffer) {
  ssize_t read_size = read(my_sock, buffer, kBufferSize-1);
  std::cout << "Received: " << buffer << "\n";
  return read_size;
}

int main(int argc, char *argv[]) {
  std::string message = messageToSend(argc, argv);
  sockaddr_in address;
  char buffer[kBufferSize] = {0};

  int my_sock = createSocket(AF_INET, SOCK_STREAM, 0);
  if (my_sock < 0) {
    return -1;
  }

  // Set up the socket address structure
  if (socketAddressSetup(address, AF_INET) < 0) {
    return -1;
  }

  // Connect to the server
  if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {
    std::cerr << "Connection Failed\n";
    return -1;
  }
  // Send message
  sendMessage(my_sock, message);

  // Wait for reply
  readMessage(my_sock, buffer);
  
  // Close the socket
  close(my_sock);
  return 0;
}