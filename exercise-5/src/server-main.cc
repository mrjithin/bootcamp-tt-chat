#include "net/Server.h"

int main() {
  const int kPort = 8080;

  tt::chat::server::Server server(kPort);
  server.start();

  return 0;
}
