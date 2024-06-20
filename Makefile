CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

all: first

first.o: scenarios/first.cpp *.cpp
	$(CC) $(CFLAGS) -c scenarios/first.cpp *.cpp

second.o: scenarios/second.cpp *.cpp
	$(CC) $(CFLAGS) -c scenarios/second.cpp

third.o: scenarios/third.cpp *.cpp
	$(CC) $(CFLAGS) -c scenarios/third.cpp

forth.o: scenarios/forth.cpp *.cpp
	$(CC) $(CFLAGS) -c scenarios/forth.cpp

first: first.o
	$(CC) $(CFLAGS) -o first *.o

second: second.o
	$(CC) $(CFLAGS) -o second *.o

third: third.o
	$(CC) $(CFLAGS) -o third *.o

forth: forth.o
	$(CC) $(CFLAGS) -o forth *.o


clean:
	rm -f *.o