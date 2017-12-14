CFLAGS=-c -Wall
SOURCES=$(wildcard **/*.cpp)
OBJECTS=$(subst .cpp,.o,$(SOURCES))

boomlin: $(OBJECTS) resources.o
	g++ $(OBJECTS) resources.o -o $@ `pkg-config gtkmm-3.0 --libs`

%.o: %.cpp
	g++ $(CFLAGS) $< -o $@ `pkg-config gtkmm-3.0 --cflags`

resources.cpp:
	glib-compile-resources --target=resources.cpp --generate-source boomlin.gresource.xml

clean:
	rm -rf *.o boomlin
