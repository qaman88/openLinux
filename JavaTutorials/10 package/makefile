# Compiler Info
JAVAC   = javac
# this < -d . > command put package on this directory
JFLAGS  = -d . 

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = Hello.java
PACKAGE = mypackage

# Gabbage to clean
GABBAGE = $(PACKAGE) *.class

# Compile Source Files
$(TARGET:.java=.class):
	$(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET)

# Rum Driver Main Function
run:
	java $(PACKAGE)/$(TARGET:.java=)

# Clean Gabbage
clean:
	 @rm -f -r  $(GABBAGE)
	 @reset
     
# redo = clean, compile and run
redo:
	 $(MAKE) -s clean
	 $(MAKE) -s $(TARGET:.java=.class)
	 $(MAKE) -s run
