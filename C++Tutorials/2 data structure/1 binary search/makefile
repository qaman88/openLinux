# Compiler Info
GCC     = g++
CFLAGS  = -std=c++14

# Sorce Files 
TARGET  = main.cpp
SOURCES = 

# Gabbage to clean
GABBAGE =  $(TARGET:.cpp=) *.out

# Compile Source Files
start:
	$(GCC) $(CFLAGS) $(SOURCES) $(TARGET) -o $(TARGET:.cpp=)

# Rum Driver Main Function
run:
	./$(TARGET:.cpp=)

# Clean Gabbage
clean:
	 @rm -f -r  $(GABBAGE)
	 @reset
     
# redo = clean, compile and run
redo:
	 $(MAKE) -s clean
	 $(MAKE) -s start
	 $(MAKE) -s run
