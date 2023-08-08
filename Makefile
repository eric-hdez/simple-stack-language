CC = clang++
CPPFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Werror
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = main

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

tidy:
	rm -f $(OBJ)

clean: tidy
	rm -f $(BIN)

debug: CFLAGS += -g -DDEBUG_ENABLED
debug: all
