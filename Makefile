CFLAGS=-c -Wall
SOURCES=$(wildcard **/*.cpp)
OBJECTS=$(subst .cpp,.o,$(SOURCES))
RESOURCEDEPS = boomlin.gresource.xml window.ui

boomlin: $(OBJECTS) resources.o
	g++ $(OBJECTS) resources.o -o $@ `pkg-config gtkmm-3.0 --libs`

%.o: %.cpp
	g++ $(CFLAGS) $< -o $@ `pkg-config gtkmm-3.0 --cflags`

resources.cpp: $(RESOURCEDEPS)
	glib-compile-resources --target=resources.cpp --generate-source boomlin.gresource.xml

clean:
	rm -rf *.o boomlin
