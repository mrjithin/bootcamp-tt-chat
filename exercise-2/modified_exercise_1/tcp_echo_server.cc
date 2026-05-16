#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

const int kPort = 8080;
const int kBufferSize = 1024;

// Creates a socket and sets the necessary options
auto createSocket(auto family, auto type, auto protocol,auto opt) {
  int my_sock;

  // Creating socket file descriptor
  if ((my_sock = socket(family, type, protocol)) < 0) {
    std::cerr << "Socket creation error\n";
    return -1;
  }

  // Attaching socket to port
  if (setsockopt(my_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    std::cerr << "setsockopt error\n";
    return -1;
  }
  return my_sock;
}

// Sets up the address structure for the server
auto setupAddress(auto &address) {
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(kPort);
}

// Configures the server by binding the socket and starting to listen
auto configureServer(auto &my_sock, auto &address) {
  // Bind the socket to the network address and port
  if (bind(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {
    std::cerr << "bind failed\n";
    return -1;
  }
  // Start listening for incoming connections
  if (listen(my_sock, 3) < 0) {
    std::cerr << "listen failed\n";
    return -1;
  }
  std::cout << "Server listening on port " << kPort << "\n";
  return 0;
}

// Handles incoming connections and sends back echo messages
auto handleClient(auto &new_sock, auto &buffer) {
  // Wait for read
  ssize_t read_size = read(new_sock, buffer, kBufferSize-1);
  std::cout << "Received: " << buffer << "\n";

  // Send reply
  send(new_sock, buffer, read_size, 0);
  std::cout << "Echo message sent" << "\n";
}

int main() {
  sockaddr_in address;
  socklen_t addrlen = sizeof(address);
  char buffer[kBufferSize] = {0};
  int my_sock;
  int opt = 1;

  my_sock = createSocket(AF_INET, SOCK_STREAM, 0, opt);

  setupAddress(address);

  configureServer(my_sock, address);
  
  // Handle incoming connections in an infinite loop
  while (true) {
    int new_sock = accept(my_sock, (struct sockaddr *)&address, &addrlen);
    if (new_sock < 0) {
      std::cerr << "accept error\n";
      return -1;
    }
    handleClient(new_sock, buffer);
    close(new_sock);
  }

  close(my_sock);
  return 0;
}