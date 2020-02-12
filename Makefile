CC = gcc
CFLAGS = -Wall -O1 -std=gnu11 -lpthread
OBJS = myThread.o mysem.o

.DEFAULT_GOAL := compileSem
.PHONY: compileSem compileNoSem clean

compileSem: clean mysem compile

compileNoSem: clean nosem compile

mysem:
	sed -i 's/#define MUTEX NONE/#define MUTEX MYSEM/' myThread.c

nosem:
	sed -i 's/#define MUTEX MYSEM/#define MUTEX NONE/' myThread.c

compile: $(OBJS)
	$(CC) $(CFLAGS) -o myThread $(OBJS)

myThread.o: myThread.c myThread.h
mysem.o: mysem.c mysem.h

clean:
	rm -f myThread $(OBJS)

