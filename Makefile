all: run

TESTS_DIR="tests/"
TESTS_NAME="*_test.c"
TESTS_FILES=$(shell ls -1 "$(TESTS_DIR)$(TESTS_NAME)")
TESTS_BIN_DIR=target/tests/
TESTS_RESULTS_DIR=target/tests_res/

build: lib/ lib/*.c main.c target/
	gcc main.c lib/*.c -o target/bin

build-tests: $(TESTS_BIN_DIR)
	@for file in $(notdir $(basename $(TESTS_FILES))); do \
		echo "Builing" $$file; \
		gcc lib/*.c $(TESTS_DIR)$$file.c unity/*.c -o $(TESTS_BIN_DIR)$$file; \
	done;

launch-tests: $(TESTS_BIN_DIR)/* $(TESTS_RESULTS_DIR)
	@for file in $(notdir $(shell ls -1 "$(TESTS_BIN_DIR)")); do \
		echo "Executing" $$file; \
		$(TESTS_BIN_DIR)$$file > $(TESTS_RESULTS_DIR)$$file.txt; \
	done;

run: lib/ lib/*.c main.c
	make build && ./target/bin
