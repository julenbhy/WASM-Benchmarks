compile:
	/opt/wasi-sdk/bin/clang ../../benchmark.c -Wl,--max-memory=4294967296 -O3 -o clang.wasm
	# maximum memory must be 65536-byte (64kiB) aligned, cannot be greater than 4294967296 (4GiB)
	#67108864 = 64MiB
	
	#emcc ../../benchmark.c -s TOTAL_MEMORY=4GB -s MALLOC='emmalloc' -O3 -o emcc.wasm
	#emcc ../../benchmark.c -s ALLOW_MEMORY_GROWTH=1 -s MAXIMUM_MEMORY=4294967296 -s MALLOC='emmalloc' -O3 -o emcc.wasm
	emcc ../../benchmark.c -s ALLOW_MEMORY_GROWTH=1 -s MAXIMUM_MEMORY=4294967296 -O3 -o emcc.wasm


1G:
	wasmtime clang.wasm 1073741824

2G:
	wasmtime clang.wasm 2147483648


multitime:
	
	multitime $(PARAMS) wasmtime --dynamic-memory-reserved-for-growth 4294967296 clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.time
	
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

