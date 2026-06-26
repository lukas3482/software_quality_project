BUILD_DIR := build
CMAKE     := cmake

.PHONY: all build test clean check install-deps

all: build test check

# C

build:
	$(CMAKE) -S c -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release
	$(CMAKE) --build $(BUILD_DIR) --parallel

test: build install-deps
	cd $(BUILD_DIR) && ctest --output-on-failure
	cd python && python -m pytest tests/ -v

clean:
	$(CMAKE) -E rm -rf $(BUILD_DIR)

check: build install-deps
	clang-tidy -p $(BUILD_DIR) --warnings-as-errors=* c/src/calculator.c
	cd python && python -m ruff check .

# Python 
install-deps:
	pip install -r requirements.txt
