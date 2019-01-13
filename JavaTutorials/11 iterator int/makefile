# Compiler Info
JAVAC   = javac
JFLAGS  = -g

# Java Sorce Files 
TARGET  = Driver.java
SOURCES =

# Compile Source Files
$(TARGET:.java=.class):
	$(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET) 

# Rum Driver Main Function
run:
	java $(TARGET:.java=)


redo:
	 @reset
	 @rm -f *.class
	 $(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET)
	 java $(TARGET:.java=)



# Clean Gabbage
clean:
	 @rm -f *.class
	 @reset
     

