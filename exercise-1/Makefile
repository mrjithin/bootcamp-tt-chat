CXX := g++
CXXFLAGS := -Wall -Wextra -O2
BUILD_DIR := build
SRC_DIR := src

TARGETS := $(BUILD_DIR)/server $(BUILD_DIR)/client

.PHONY: all clean directories

all: directories $(TARGETS)

directories:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/server: $(SRC_DIR)/tcp_echo_server.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/client: $(SRC_DIR)/tcp_echo_client.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)