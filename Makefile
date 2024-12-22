EMSDK_DIR ?= ${HOME}/git/emsdk

all: test.wasm

test.wasm: test.cc
	(source ${EMSDK_DIR}/emsdk_env.sh; em++ -O2 -Wl,--no-entry $^ -o test.wasm)

.PHONY: clean

clean:
	rm -f test.wasm
