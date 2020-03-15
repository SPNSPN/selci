GCC := gcc -std=c99
CFLAGS := -O2 -Wall -Iinclude
DBGCFLAGS := -g3 -O0 -Wall -Iinclude

SRC := src
INC := include
BLD := build

SRCS := $(filter-out $(SRC)/repl.c $(SRC)/test.c, $(wildcard $(SRC)/*.c))
OBJS := $(patsubst $(SRC)/%.c,$(BLD)/%.o,$(SRCS))

REPL := $(BLD)/repl
TEST := $(BLD)/test

.PHONY: all
all: $(REPL) $(TEST)

repl: $(REPL)
	rlwrap $(BLD)/repl

test: $(TEST)
	$(BLD)/test

$(REPL): $(OBJS) $(SRC)/repl.c
	$(GCC) $(CFLAGS) -c -o $(REPL).o $(SRC)/repl.c
	$(GCC) -o $@ $(OBJS) $(REPL).o

$(TEST): $(OBJS) $(SRC)/test.c
	$(GCC) $(CFLAGS) -c -o $(TEST).o $(SRC)/test.c
	$(GCC) -o $@ $(OBJS) $(TEST).o

$(BLD)/%.o: $(SRC)/%.c
	$(GCC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm $(BLD)/*

