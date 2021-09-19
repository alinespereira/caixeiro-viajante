CC        := gcc

BIN       := ./bin
OBJ       := ./obj
INCLUDE   := ./include
SRC       := ./src
MAIN_FILE := $(SRC)/main.c
SRC_FILES := $(filter-out $(MAIN_FILE), $(wildcard $(SRC)/*.c))
OBJ_FILES := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRC_FILES))

PROGRAM   := $(BIN)/main

CFLAGS    := -I$(INCLUDE) -Wall -Wpedantic -std=c99 -lm

all: $(PROGRAM)

$(PROGRAM): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(MAIN_FILE) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(PROGRAM)
	$<

clean:
	rm -rf $(PROGRAM) $(OBJ_FILES)