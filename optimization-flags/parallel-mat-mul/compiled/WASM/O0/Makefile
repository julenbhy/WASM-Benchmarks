compile:
	/opt/wasi-sdk/bin/clang --target=wasm32-wasi-threads -pthread -Wl,--import-memory,--export-memory,--max-memory=1310720000 ../../../benchmark.c -o clang.wasm -D$(SIZE)_DATASET
# maximum memory must be 65536-byte (64kiB) aligned, cannot be greater than 4294967296 (4GiB)
#67108864 = 64MiB
#	emcc -pthread ../../benchmark.c -o emcc.wasm -D$(SIZE)_DATASET


WT_FLAGS = --wasm-features=threads --wasi-modules=experimental-wasi-threads
multitime:
	
	multitime $(PARAMS) wasmtime $(WT_FLAGS) clang.wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > clang-wasmtime.time
	
#	multitime $(PARAMS) wasmtime $(WT_FLAGS) emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.time
	
#	multitime $(PARAMS) wasmedge --enable-threads clang.wasm 2>&1 | sed '1,2d' > clang-wasmedge.time
	
#	multitime $(PARAMS) wasmedge --enable-threads emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmedge.time
	
	multitime $(PARAMS) iwasm --max-threads=$(NUM_THREADS) clang.wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > clang-wamr.time
	
#	multitime $(PARAMS) iwasm --max-threads=1000 emcc.wasm 2>&1 | sed '1,2d' > emcc-wamr.time
	 

strace:
	
	strace $(PARAMS) wasmtime $(WT_FLAGS) clang.wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > clang-wasmtime.strace
	
#	strace $(PARAMS) wasmtime $(WT_FLAGS) emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.strace
	
#	strace $(PARAMS) wasmedge --enable-threads clang.wasm 2>&1 | sed '1,2d' > clang-wasmedge.strace
	
#	strace $(PARAMS) wasmedge --enable-threads emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmedge.strace
	
	strace $(PARAMS) iwasm --max-threads=$(NUM_THREADS) clang.wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > clang-wamr.strace
	
#	strace $(PARAMS) iwasm --max-threads=$(NUM_THREADS) emcc.wasm 2>&1 | sed '1,2d' > emcc-wamr.strace

