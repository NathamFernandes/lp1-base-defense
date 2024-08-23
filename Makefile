NAME = game

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

CC = g++
CFLAGS = -I ./$(INCLUDE_DIR) -pedantic -Wall -Wextra -ansi -std=c++11
ALLEGRO_FLAGS = -lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec

EXE = $(BIN_DIR)/$(NAME)

_DEPS = game.h base.h player.h enemy.h random.h constants.h shot.h drop.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJS = main.o game.o model/base.o model/player.o model/enemy.o utils/random.o model/shot.o model/drop.o
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

all: directories $(EXE)

directories:
	mkdir -p $(BIN_DIR) $(OBJ_DIR) $(OBJ_DIR)/model $(OBJ_DIR)/utils

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(ALLEGRO_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

run: all
	./$(EXE)

.PHONY: clean

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
