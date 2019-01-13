# Compiler Info
JAVAC   = javac
JFLAGS  = -g

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = 
GABBAGE = file.out Data.gzip $(SOURCES:.java=.class)  $(TARGET:.java=.class)

# Drive Main Function
MAIN    = Driver

# Compile Source Files
$(MAIN).class: $(SOURCES) 
	$(JAVAC)  $(JFLAGS) $(TARGET)

# Rum Driver Main Function
run:
	java $(MAIN) "Ngobeni" 

redo:
	@rm -f $(GABBAGE)
	$(JAVAC)  $(JFLAGS) $(TARGET)
	java $(MAIN) "Ngobeni"

# Clean Gabbage
clean:
	 @rm -f $(GABBAGE)

