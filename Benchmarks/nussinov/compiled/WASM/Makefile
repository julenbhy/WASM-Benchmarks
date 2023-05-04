compile:
	emcc ../../benchmark.c -I ../../utilities ../../utilities/polybench.c -D$(SIZE)_DATASET -s TOTAL_MEMORY=64MB -w -o emcc.wasm
	

multitime:
	multitime $(PARAMS) wasmtime emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.time
	 
	 
strace:
	strace $(PARAMS) wasmtime emcc.wasm 2>&1 | sed '1,2d' > emcc-wasmtime.strace


