CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra $(shell pkg-config --cflags x11)
LDFLAGS  := $(shell pkg-config --libs x11)

TARGET   := chess
SRC      := main.c object.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
