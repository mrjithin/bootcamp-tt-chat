CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

SRC_DIR = src
BUILD_DIR = build

SERVER = $(BUILD_DIR)/server
CLIENT = $(BUILD_DIR)/client

all: $(SERVER) $(CLIENT)

$(SERVER): $(BUILD_DIR)/setup.o $(SRC_DIR)/tcp_echo_server.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/tcp_echo_server.cpp $(BUILD_DIR)/setup.o -o $(SERVER)

$(CLIENT): $(BUILD_DIR)/setup.o $(SRC_DIR)/tcp_echo_client.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/tcp_echo_client.cpp $(BUILD_DIR)/setup.o -o $(CLIENT)

$(BUILD_DIR)/setup.o: $(SRC_DIR)/setup.cpp $(SRC_DIR)/setup.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/setup.cpp -o $(BUILD_DIR)/setup.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)