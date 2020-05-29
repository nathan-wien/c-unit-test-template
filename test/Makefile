CC=gcc
CFLAGS=-std=gnu99 -Wall -Wextra -Werror -pedantic -g

SRC_DIR:=..
OBJ_DIR:=..
SRCS:=$(wildcard $(SRC_DIR)/*.c)
SRCS:=$(filter-out $(SRC_DIR)/main.c, $(SRCS))
OBJS:=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

UNITY_ROOT:=Unity
UNITY_DIR:=$(UNITY_ROOT)/src
UNITY_SRCS:=$(UNITY_DIR)/unity.c
UNITY_OBJS:=$(UNITY_DIR)/unity.o

UNITY_CODEGEN:=$(UNITY_ROOT)/auto/generate_test_runner.rb

TEST_DIR=.
TEST_SRCS:=$(TEST_DIR)/test.c $(TEST_DIR)/testRunner.c
TEST_OBJS:=$(patsubst $(TEST_DIR)/%.c,$(TEST_DIR)/%.o,$(TEST_SRCS))

ALL_SRCS:=$(SRCS) $(UNITY_SRCS) $(TEST_SRCS)
ALL_OBJS:=$(OBJS) $(UNITY_OBJS) $(TEST_OBJS)

INC=-I$(UNITY_ROOT)/src -I$(SRC_DIR)

EXEC:=test

.PHONY: all $(EXEC) clean

all: $(EXEC)

$(EXEC): $(ALL_OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(UNITY_DIR)/%.o: $(UNITY_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TEST_DIR)/testRunner.c: $(TEST_DIR)/test.c
	ruby $(UNITY_CODEGEN) $< $@

clean:
	rm $(EXEC) $(ALL_OBJS)
