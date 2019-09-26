CC = gcc
LDLIBS = -L/usr/lib -lm -ljpeg -pthread
Driver = create
Target = createthreads.c
Driver2 = return 
Target2 = returnthread.c
Driver3 = root 
Target3 = squareRootThread.c
Sources = createthreads.c returnthread.c squareRootThread.c

make: 
	$(CC) -c $(Sources)
	$(CC) -o $(Driver) $(Target) $(LDLIBS)
	$(CC) -o $(Driver2)  $(Target2) $(LDLIBS)
	$(CC) -o $(Driver3)  $(Target3) $(LDLIBS)

runc: 
	./$(Driver)

runr:
	./$(Driver2)

runs:
	./$(Driver3)

clean:
	rm -r *.o *~* $(Driver)  $(Driver2)  $(Driver3)
