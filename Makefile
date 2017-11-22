CFLAGS=-c -Wall
SOURCES=$(wildcard **/*.cpp)
OBJECTS=$(subst .cpp,.o,$(SOURCES))

boomlin: $(OBJECTS)
	g++ $(OBJECTS) -o $@ `pkg-config gtkmm-3.0 --libs`

%.o: %.cpp
	g++ $(CFLAGS) $< -o $@ `pkg-config gtkmm-3.0  --cflags`

clean:
	rm -rf *.o boomlin
