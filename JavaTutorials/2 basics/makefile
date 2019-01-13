# Compiler Info
JAVAC   = javac
JFLAGS  = -g

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = 

# Drive Main Function
MAIN    = Driver

# Compile Source Files
$(MAIN).class: $(SOURCES) 
	$(JAVAC)  $(JFLAGS) $(TARGET)

# Rum Driver Main Function
run:
	java $(MAIN)

# Clean Gabbage
clean:
	 @rm -f  $(SOURCES:.java=.class)  $(TARGET:.java=.class)

