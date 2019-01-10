CC      = g++
CFLAGS  =  -std=c++11 -I /home/expertcyclone/boost/include
LDFLAGS =  -std=c++11 -I /home/expertcyclone/boost/include \
            /home/expertcyclone/boost/lib/libboost_system.a \
            -lpthread

all: main

main: main.o 
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.cpp
	$(CC) -c $(CFLAGS) $<

run:
	./main

.PHONY: clean 

clean:
	rm *.o main
	reset

