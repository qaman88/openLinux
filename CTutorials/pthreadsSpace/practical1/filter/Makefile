CC = gcc
LDLIBS = -L/usr/lib -lm -ljpeg -pthread
Driver = main
Target = medianFilter.c 
Target2 = matrix_filler.c
Sources = matrix_filler.c

make: 
	$(CC) -c $(Sources) 
	$(CC) -o $(Driver) $(Target2) $(LDLIBS)

run: 
	./$(Driver)
	

clean:
	rm -r *.o *~* $(Driver) 
