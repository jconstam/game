CURR_DIR=$(shell pwd)

BIN_DIR=bin

run: build
	./$(BIN_DIR)/Game

build:
	mkdir -p $(BIN_DIR)
	cd $(BIN_DIR) && cmake "$(CURR_DIR)"
	make -C $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)
