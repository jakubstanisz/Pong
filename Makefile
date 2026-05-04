CC = g++
CFLAGS = -Wall -std=c++17 -Iinclude
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = gra

SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard include/*.hpp)

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)