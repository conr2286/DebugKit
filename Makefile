CFLAGS= -std=c17 
PGM = test
OBJS= DebugKit.o


#-----Build just the object files
$(OBJS): rules.d Makefile

#-----Build the *.d files before the product
all:  rules.d test

#-----Builds a debug version of the test program (*must* follow make clean)
debug: CFLAGS += -Og -g -DDEBUG
debug: rules.d test

#-----Rebuild the dependency (*.d) files from their sources
rules.d: Makefile $(wildcard *.c) $(wildcard *.h)
	gcc -MM $(wildcard *.c) >rules.d

#-----Include the header dependency rules into this Makefile
-include rules.d

#-----Rebuild the test program
test: $(OBJS) test.o Makefile
	gcc test.o $(OBJS)  -o $@

clean:
	rm -f *.o test  *~ *.d

