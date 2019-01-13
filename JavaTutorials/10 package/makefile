# Compiler Info
JAVAC   = javac
JFLAGS  = -g -d .

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = Hello.java
PACKAGE = mypackage

# Gabbage to clean
GABBAGE = $(PACKAGE)

# Compile Source Files
$(TARGET:.java=.class):
	$(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET)

# Rum Driver Main Function
run:
	java $(PACKAGE)/$(TARGET:.java=)

redo:
	 @reset
	 @rm -r $(GABBAGE)
	 $(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET)
	 java $(PACKAGE)/$(TARGET:.java=)

# Clean Gabbage
clean:
	 @rm -r $(GABBAGE)
	 @reset
     

