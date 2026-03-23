
CC     := gcc
CFLAGS := -Wall -Wextra $(shell pkg-config --cflags x11)
LDFLAGS := $(shell pkg-config --libs x11) -lm

OBJS := main.o App.o Renderer.o Table.o Cell.o Event.o Queen.o Array.o

all: xChess

xChess: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

main.o: main.c App.h Renderer.h Table.h Event.h
	$(CC) $(CFLAGS) -c main.c -o main.o

App.o: App.c App.h Renderer.h Table.h Event.h
	$(CC) $(CFLAGS) -c App.c -o App.o

Renderer.o: Renderer.c Renderer.h
	$(CC) $(CFLAGS) -c Renderer.c -o Renderer.o

Table.o: Table.c Table.h Cell.h Vec2.h
	$(CC) $(CFLAGS) -c Table.c -o Table.o

Cell.o: Cell.c Cell.h Vec2.h Queen.h Renderer.h
	$(CC) $(CFLAGS) -c Cell.c -o Cell.o

Event.o: Event.c Event.h
	$(CC) $(CFLAGS) -c Event.c -o Event.o

Queen.o: Queen.c Queen.h Vec2.h
	$(CC) $(CFLAGS) -c Queen.c -o Queen.o

Array.o: array.c Array.h
	$(CC) $(CFLAGS) -c array.c -o Array.o



clean:
	rm -f *.o xChess

.PHONY: all clean
