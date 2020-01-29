HEADER_DIR = include
SRC = $(wildcard src/*.c)
TEST = $(wildcard tests/*.c)

test: $(SRC) $(TEST)
	@gcc -std=c99 -Wall -I$(HEADER_DIR) $(SRC) $(TEST) -o test && ./test && rm test