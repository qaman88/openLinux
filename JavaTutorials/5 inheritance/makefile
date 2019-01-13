# Compiler Info
JAVAC   = javac
JFLAGS  = -g

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = Point.java Line.java Triangle.java Rectangle.java

# Drive Main Function
MAIN    = Driver

# Compile Source Files
$(MAIN).class:
	$(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET) 

# Rum Driver Main Function
run:
	java $(MAIN)

redo:
	 @rm -f  $(SOURCES:.java=.class)  $(TARGET:.java=.class)
	 @reset
	 $(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET)
	 java $(MAIN)


# Clean Gabbage
clean:
	 @rm -f  $(SOURCES:.java=.class)  $(TARGET:.java=.class)
	 @reset
     

