CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra $(shell pkg-config --cflags x11)
LDFLAGS  := $(shell pkg-config --libs x11)

TARGET   := chess
SRC      := main.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
