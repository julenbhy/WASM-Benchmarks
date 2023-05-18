compile:
	emcc ../../benchmark.c -I ../../utilities ../../utilities/polybench.c -D$(SIZE)_DATASET -s TOTAL_MEMORY=64MB -O3 -o emcc.wasm
	
	/opt/wasi-sdk/bin/clang ../../benchmark.c -I ../../utilities ../../utilities/polybench.c -D$(SIZE)_DATASET -D_WASI_EMULATED_PROCESS_CLOCKS -O3 -o clang.wasm

	
multitime:
	
	multitime $(PARAMS) wasmtime clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.time
	
	multitime $(PARAMS) wasmtime emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.time
	
	multitime $(PARAMS) wasmedge clang.wasm 2>&1 | sed '1,2d' > clang-wasmedge.time
	
	multitime $(PARAMS) wasmedge emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmedge.time
	
	multitime $(PARAMS) iwasm clang.wasm 2>&1 | sed '1,2d' > clang-wamr.time
	
	multitime $(PARAMS) iwasm emcc.wasm 2>&1 | sed '1,2d' > emcc-wamr.time
	 

strace:
	
	strace $(PARAMS) wasmtime clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.strace
	
	strace $(PARAMS) wasmtime emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.strace
	
	strace $(PARAMS) wasmedge clang.wasm 2>&1 | sed '1,2d' > clang-wasmedge.strace
	
	strace $(PARAMS) wasmedge emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmedge.strace
	
	strace $(PARAMS) iwasm clang.wasm 2>&1 | sed '1,2d' > clang-wamr.strace
	
	strace $(PARAMS) iwasm emcc.wasm 2>&1 | sed '1,2d' > emcc-wamr.strace



