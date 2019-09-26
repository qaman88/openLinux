# Compiler Info
JAVAC   = javac
JFLAGS  = -g

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = Rectangle.java Circle.java Extras.java Triangle.java Shape.java

# Compile Source Files
$(TARGET:.java=.class):
	$(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET) 

# Rum Driver Main Function
run:
	java $(TARGET:.java=)

redo:
	 @reset
	 @rm -f  $(SOURCES:.java=.class)  $(TARGET:.java=.class)
	 $(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET)
	 java $(TARGET:.java=)


# Clean Gabbage
clean:
	 @rm -f  $(SOURCES:.java=.class)  $(TARGET:.java=.class)
	 @reset
     

