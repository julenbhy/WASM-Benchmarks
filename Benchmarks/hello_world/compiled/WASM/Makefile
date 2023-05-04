compile:
	/opt/wasi-sdk/bin/clang ../../benchmark.c -o clang.wasm
	emcc ../../benchmark.c -o emcc.wasm -D$(SIZE)_DATASET


multitime:
	
	multitime $(PARAMS) wasmtime clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.time
	
	multitime $(PARAMS) wasmtime emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.time
	
	multitime $(PARAMS) wasmedge clang.wasm 2>&1 | sed '1,2d' > clang-wasmedge.time
	
	multitime $(PARAMS) wasmedge emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmedge.time
	 

strace:
	
	strace $(PARAMS) wasmtime clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.strace

	strace $(PARAMS) wasmtime emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.strace

	strace $(PARAMS) wasmedge clang.wasm 2>&1 | sed '1,2d' > clang-wasmedge.strace

	strace $(PARAMS) wasmedge emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmedge.strace


