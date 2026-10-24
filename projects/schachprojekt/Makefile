# Makefile for gtest examples

G++ = g++
G++_FLAGS = -std=c++17 -c -Wall -Wextra -Wpedantic
LD_FLAGS = -L /usr/local/lib -l pthread

OBJECTS = main.o board.o movement.o
TARGET = projectChess

vpath movement.cpp Movement

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

%.o : %.cpp
	$(G++) $(G++_FLAGS) $<

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
