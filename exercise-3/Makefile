CXX := g++
CXXFLAGS := -Wall -Wextra -O2 -fsanitize=address
LDFLAGS := -fsanitize=address
BUILD_DIR := build
SRC_DIR := src

TARGETS := $(BUILD_DIR)/server $(BUILD_DIR)/client

.PHONY: all clean directories

all: directories $(TARGETS)

directories:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/server: $(SRC_DIR)/tcp_echo_server.cc
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/client: $(SRC_DIR)/tcp_echo_client.cc
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)