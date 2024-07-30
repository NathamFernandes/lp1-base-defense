NAME = game

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
BIN_DIR = bin

CC = g++
CFLAGS = -I$(INCLUDE_DIR) -pedantic -Wall -Wextra -ansi -std=c++11
ALLEGROFLAGS = $(shell pkg-config allegro-5 allegro_font-5 --libs --cflags)

EXECUTABLE = $(BIN_DIR)/$(NAME)

_DEPS = game.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJS = main.o game.o
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(ALLEGROFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

run: all
	./$(EXECUTABLE)

.PHONY: clean

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
