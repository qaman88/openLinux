# This Makefile requires GNU make, which is called gmake on Solaris systems
#
# 'make'        : build blear and serial
# 'make clean'  : remove build products

PROG = blur serial parallel

OBJS = $(PROG:%=%.o)

ARCH=$(shell uname -m)
OS=$(shell uname -s)

CC = gcc

LDLIBS = -L/usr/lib -lm -ljpeg -pthread

.PHONY: default clean

all: $(PROG)

blur: 
	$(CC) -c ../src/blur.c
	$(CC) -o blur blur.o $(LDLIBS)
	
serial:
	$(CC) -c ../src/serial.c
	$(CC) -o serial serial.o $(LDLIBS)
	
parallel:
	$(CC) -c ../src/parallel.c
	$(CC) -o parallel parallel.o $(LDLIBS)
	
assem: 
	$(CC) -S pa1-p1.c

run1:
	 ./serial 1 4 ../Pic/small.jpg result1.jpg
	 
run2: 
	 ./blur 1 4 ../Pic/small.jpg result2.jpg
	 
run3:
	 ./parallel 1 4 ../Pic/small.jpg result3.jpg
	
clean:
	rm -f $(PROG) $(OBJS) *.o *.jpg
