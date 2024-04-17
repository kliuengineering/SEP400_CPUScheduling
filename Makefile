CC=g++
CFLAGS=-I.
CFLAGS+=-Wall
FILES1=nestedLoop2.cpp
FILES2=systemMonitor.cpp

nLoop2: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

systemMonitor: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o nLoop2 systemMonitor

all: nLoop2 systemMonitor
