CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-parameter
TARGET = zozsh
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
