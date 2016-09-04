CURR_DIR=$(shell pwd)

BIN_DIR=bin

build:
	mkdir -p $(BIN_DIR)
	cd $(BIN_DIR) && cmake "$(CURR_DIR)"
	make -C $(BIN_DIR)

run: build
	./$(BIN_DIR)/Game

clean:
	rm -rf $(BIN_DIR)
