# Compiler Info
JAVAC   = javac
JFLAGS  = -g

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = Kid.java Girl.java Boy.java

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
     

