
CC     := gcc
CFLAGS := -Wall -Wextra -Iinclude $(shell pkg-config --cflags x11)
LDFLAGS := $(shell pkg-config --libs x11) -lm

SRCS := src/main.c src/App.c src/Renderer.c src/Table.c src/Cell.c src/Event.c src/Queen.c src/Array.c
OBJS := $(patsubst src/%.c, build/%.o, $(SRCS))

all: build xChess

xChess: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

build:
	mkdir -p build

build/main.o: src/main.c include/App.h include/Renderer.h include/Table.h include/Event.h
	$(CC) $(CFLAGS) -c $< -o $@

build/App.o: src/App.c include/App.h include/Renderer.h include/Table.h include/Event.h
	$(CC) $(CFLAGS) -c $< -o $@

build/Renderer.o: src/Renderer.c include/Renderer.h
	$(CC) $(CFLAGS) -c $< -o $@

build/Table.o: src/Table.c include/Table.h include/Cell.h include/Vec2.h
	$(CC) $(CFLAGS) -c $< -o $@

build/Cell.o: src/Cell.c include/Cell.h include/Vec2.h include/Queen.h include/Renderer.h
	$(CC) $(CFLAGS) -c $< -o $@

build/Event.o: src/Event.c include/Event.h include/App.h
	$(CC) $(CFLAGS) -c $< -o $@

build/Queen.o: src/Queen.c include/Queen.h include/Vec2.h
	$(CC) $(CFLAGS) -c $< -o $@

build/Array.o: src/Array.c include/Array.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build/ xChess

.PHONY: all clean build
