CC=g++
CFLAGS=-g -c -std=c++11 -O2

SOURCES=$(shell find . -type f -name '*.cpp' )
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=battle.out

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -fv $(OBJECTS)

purge:
	find . -type f \( -name '*.o' -o -name '*.out' \) -exec rm -fv {} \;
