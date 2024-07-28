NAME = game

BIN_DIR = bin

CC = g++
CFLAGS = -pedantic -Wall -Wextra -ansi -std=c++11
ALLEGROFLAGS = $(shell pkg-config allegro-5 allegro_font-5 --libs --cflags)

EXECUTABLE = $(BIN_DIR)/$(NAME)

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(BIN_DIR)

$(EXECUTABLE): main.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(ALLEGROFLAGS)

run: all
	./$(EXECUTABLE)

.PHONY: clean

clean:
	rm -f $(BIN_DIR)
