BIN = ./a.out
CC=g++
CCFLAGS = -I ./ -c -Wall -Wextra -pthread 
CCFLAGS+= -m64 -O0 -g -pedantic
LDFLAGS = -pthread -m64

SRCS=$(wildcard ./*.cpp)

OBJS=$(SRCS:.cpp=.o)

.PHONY: all
all: $(BIN)

$(BIN):$(OBJS)
						$(CC) $(OBJS) -o $@ $(LDFLAGS)
						
%.o:%.cpp
						$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY: valgrind 
valgrind:				# check for memory leak
						$(info -- Checking For Memory Leaks --)
						make
						valgrind --leak-check=full --show-leak-kinds=all ./a.out

.PHONY: debug
debug:					# GNU debugger
						$(info -- Debugging --)
						gdb ./a.out

.PHONY: clean
clean:					# clean the directory
						$(info -- Cleaning The Directory --)
						rm -rf ./*.o ./a.out
.PHONY: run
run:					# run the program as follows
						$(info -- Running Program --)
						make
						./a.out
