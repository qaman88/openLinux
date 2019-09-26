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

# Rum Driver Main Function
run2:
	java $(MAIN) "Tlamangile"


# Clean Gabbage
clean:
	 @rm -f  $(SOURCES:.java=.class)  $(TARGET:.java=.class)

