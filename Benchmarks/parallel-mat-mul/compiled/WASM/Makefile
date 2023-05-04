compile:
	/opt/wasi-sdk/bin/clang --target=wasm32-wasi-threads -pthread -Wl,--import-memory,--export-memory,--max-memory=67108864 ../../benchmark.c -o clang.wasm -D$(SIZE)_DATASET


FLAGS = --wasm-features=threads --wasi-modules=experimental-wasi-threads
multitime:
	multitime $(PARAMS) wasmtime $(FLAGS) clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.time


strace:
	strace $(PARAMS) wasmtime $(FLAGS) clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.strace


