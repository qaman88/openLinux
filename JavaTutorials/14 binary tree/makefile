# Compiler Info
JAVAC   = javac
JFLAGS  = -g -d .   # store package on this directory

# Java Sorce Files 
TARGET  = Driver.java
SOURCES = BinaryNode.java BinaryTree.java BinaryTreeIterator.java
PACKAGE = ngobeni/java
JARFILE = binarytreeclasses.jar

# Gabbage to clean
GABBAGE = ngobeni *.class *.jar

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

jar: $(TARGET:.java=.class)
	 jar --create --file $(JARFILE) $(PACKAGE)/*

