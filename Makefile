CC = gcc
CFLAGS = -Wall -Wextra -O2 -Wno-usedparameters
TARGET = zozsh
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
