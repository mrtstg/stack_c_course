all: run

TESTS_DIR="tests/"
TESTS_NAME="*_test.c"
TESTS_FILES=$(shell ls -1 "$(TESTS_DIR)$(TESTS_NAME)")
TESTS_BIN_DIR=target/tests/
TESTS_RESULTS_DIR=target/tests_res/

pull-unity:
	git clone https://github.com/ThrowTheSwitch/Unity
	mkdir -p unity/
	mv Unity/src/* unity/
	rm -rf Unity

prepare:
	mkdir -p unity/ mkdir -p $(TESTS_BIN_DIR) && mkdir -p $(TESTS_RESULTS_DIR) && mkdir -p $(TESTS_DIR)

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
		$(TESTS_BIN_DIR)$$file > $(TESTS_RESULTS_DIR)$$file.txt || true; \
	done;

display-tests: $(TESTS_RESULTS_DIR)/*
	@echo "------------------PASSED------------------"
	@for line in $(shell grep -s PASS $(TESTS_RESULTS_DIR)*.txt); do \
		echo $$line; \
	done;
	@echo "------------------IGNORE------------------"
	@for line in $(shell grep -s IGNORE $(TESTS_RESULTS_DIR)*.txt); do \
		echo $$line; \
	done;
	@echo "-------------------FAIL-------------------"
	@for line in $(shell grep -s FAIL $(TESTS_RESULTS_DIR)*.txt); do \
		echo $$line; \
	done;
	@echo "DONE"

test: $(TEST_BIN_DIR) $(TESTS_RESULTS_DIR)
	make prepare && make build-tests && make launch-tests && make display-tests

run: lib/ lib/*.c main.c
	make prepare && make build && ./target/bin
