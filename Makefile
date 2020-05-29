CC:=gcc
CFLAGS:=-std=gnu99 -Wall -Wextra -pedantic -g

SRC_DIR:=.
OBJ_DIR:=.
SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))

EXEC:=main

.PHONY: all $(EXEC) clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXEC) $(OBJS)
