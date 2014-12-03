CC = g++ -std=c++11
CFLAGS = -c `pkg-config gtkmm-3.0 --cflags` -lcppdb
LDFLAGS = `pkg-config gtkmm-3.0 --libs` -lcppdb
SOURCE = src/

all: marcacion

marcacion: main.o marcacion.o
	$(CC) main.o marcacion.o -o Registrar_Marcacion $(LDFLAGS)
	
main.o: $(SOURCE)main.cpp
	$(CC) $(CFLAGS) $(SOURCE)main.cpp
	
marcacion.o: $(SOURCE)marcacion.cpp
	$(CC) $(CFLAGS) $(SOURCE)marcacion.cpp
	
clean:
	rm *o Registrar_Marcacion
