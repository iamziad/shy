CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-parameter
TARGET = build/shy
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
