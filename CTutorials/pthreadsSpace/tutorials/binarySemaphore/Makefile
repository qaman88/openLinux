CC = gcc
LDLIBS = -L/usr/lib -lm -ljpeg -pthread
Driver = main
Target = binarySemophore.c
Sources = binarySemophore.c

make: 
	$(CC) -c $(Sources) 
	$(CC) -o $(Driver) $(Target) $(LDLIBS)

run: 
	./$(Driver)


clean:
	rm -r *.o *~* $(Driver) 
