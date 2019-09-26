# Compiler Info
JAVAC   = javac
# this < -d . > command put package on this directory
JFLAGS  = -g -d .

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = ListNode.java LinkedList.java LinkedListIterator.java
PACKAGE = ngobeni.java

# Gabbage to clean
GABBAGE = ngobeni *.class

# Compile Source Files
$(TARGET:.java=.class):
	$(JAVAC) $(JFLAGS) $(SOURCES) $(TARGET)

# Rum Driver Main Function
run:
	java $(PACKAGE).$(TARGET:.java=)

# Clean Gabbage
clean:
	 @reset
	 @rm -f -r  $(GABBAGE)
     
# redo = clean, compile and run
redo:
	 $(MAKE) -s clean
	 $(MAKE) -s $(TARGET:.java=.class)
	 $(MAKE) -s run
