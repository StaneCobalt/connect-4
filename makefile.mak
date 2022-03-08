CC = g++ $(CCFLAGS)

CCFLAGS = -std=c++11

all: connect-4

connect-4: main.o connect-4.o
	$(CC) main.o connect-4.o -o connect-4.exe

main.o: src/main.cpp include/connect-4.h
	$(CC) -c src/main.cpp

connect-4.o: src/connect-4.cpp include/connect-4.h
	$(CC) -c src/connect-4.cpp
