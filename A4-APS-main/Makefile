all: main

CXX = g++
override CXXFLAGS += -g -Wall -std=c++17

BUILD_DIR = build

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$(BUILD_DIR)/$@"

main-debug: $(SRCS) $(HEADERS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0  $(SRCS) -o "$(BUILD_DIR)/$@"

run:
	make main && ./$(BUILD_DIR)/main

run-deug:
	make && ./$(BUILD_DIR)/main-debug

clean:
	rm -f $(BUILD_DIR)/main $(BUILD_DIR)/main-debug
