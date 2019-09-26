CC = gcc
LDLIBS = -L/usr/lib -lm -ljpeg -pthread
Driver = mutex
Target = mutexThread.c
Sources = mutexThread.c

make: 
	$(CC) -c $(Sources) 
	$(CC) -o $(Driver) $(Target) $(LDLIBS)

run: 
	./$(Driver)


clean:
	rm -r *.o *~* $(Driver) 
