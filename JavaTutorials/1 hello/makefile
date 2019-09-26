# Compiler Info
JAVAC   = javac
JFLAGS  = -g

# Java Sorce Files 
SOURCES = Driver.java

# Drive Main Function
MAIN    = Driver

# Compile Source Files
$(MAIN).class: 
	$(JAVAC)  $(JFLAGS) $(SOURCES)

# Clean Gabbage
clean:
	 @rm -f  $(SOURCES:.java=.class)

# Rum Driver Main Function
run:
	java $(MAIN)
