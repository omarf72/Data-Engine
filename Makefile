CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Iinclude

TARGET := bin/data-engine
SOURCES := $(wildcard src/*.cpp)

.PHONY: all build run clean

all: build

build: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

run: build
	./$(TARGET) $(ARGS)

clean:
	rm -rf bin
