HEADER_DIR = include
SRC = $(wildcard src/*.cpp)
TEST = $(wildcard tests/*.cpp)

test: $(SRC) $(TEST)
	@g++ -std=c++11 -Wall -I$(HEADER_DIR) $(TEST) $(SRC) -o test \
	&& test
