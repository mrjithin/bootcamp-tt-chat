#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // #Question - are these the same type?
  // No, the lhs corresponds to a string object whereas
  // the rhs is a C-style string. 
  std::string message = "Hello from client";
  if(argc>1){
    message = argv[1];
  }
  const int kPort = 8080;  // The type of lhs is int and so is the rhs
  const std::string kServerAddress = "127.0.0.1"; // The type of lhs is std::string but rhs is
  // a C-style string. 
  sockaddr_in address;
  const int kBufferSize = 1024; // type of lhs is int and so is rhs
  char buffer[kBufferSize] = {0}; // type of lhs is char array 
  // but the rhs is a array of 1024 0s which is an int array. 
  // Creating socket file descriptor
  int my_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (my_sock < 0) {
    std::cerr << "Socket creation erron\n";
    return -1;
  }
  address.sin_family = AF_INET;
  address.sin_port = htons(kPort);
  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {
    std::cerr << "Invalid address/ Address not supported\n";
    return -1;
  }
  // Connect to the server
  if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {
    std::cerr << "Connection Failed\n";
    return -1;
  }
  // Send message
  send(my_sock, message.c_str(), message.size(), 0);
  std::cout << "Sent: " << message << "\n";
  // Wait for reply
  ssize_t read_size = read(my_sock, buffer, kBufferSize);
  std::cout << "Received: " << buffer << "\n";
  // Close the socket
  close(my_sock);
  return 0;
}