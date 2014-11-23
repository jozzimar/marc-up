CC = g++ -std=c++11
CFLAGS = -c `pkg-config gtkmm-3.0 --cflags` -lcppdb
LDFLAGS = `pkg-config gtkmm-3.0 --libs` -lcppdb
SOURCE = src/

all: marcup

marcup: main.o gui_raiz.o
	$(CC) main.o gui_raiz.o -o marcup $(LDFLAGS)
	
main.o: $(SOURCE)main.cpp
	$(CC) $(CFLAGS) $(SOURCE)main.cpp
	
gui_raiz.o: $(SOURCE)gui_raiz.cpp
	$(CC) $(CFLAGS) $(SOURCE)gui_raiz.cpp
	
clean:
	rm *o marcup
