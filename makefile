CC = gcc
CCOPTS = -c -g
LINKOPTS = -g

all: avail count occur format

avail: avail.o
	$(CC) $(LINKOPTS) -o $@ $^

avail.o: avail.c avail.h
	$(CC) $(CCOPTS) -o $@ avail.c

count: count.o
	$(CC) $(LINKOPTS) -o $@ $^

count.o: count.c count.h
	$(CC) $(CCOPTS) -o $@ count.c

occur: occur.o
	$(CC) $(LINKOPTS) -o $@ $^

occur.o: occur.c occur.h
	$(CC) $(CCOPTS) -o $@ occur.c

format: format.o
	$(CC) $(LINKOPTS) -o $@ $^

format.o: format.c format.h
	$(CC) $(CCOPTS) -o $@ format.c

clean:
	rm -rf *.o avail avail.exe count count.exe occur occur.exe format format.exe *~
