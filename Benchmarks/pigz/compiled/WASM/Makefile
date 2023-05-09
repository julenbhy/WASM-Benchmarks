compile:
	mkdir src
	git clone --recurse-submodules https://github.com/bytecodealliance/wasm-parallel-gzip src
	make -C src
	head -c 1000M </dev/urandom > random.bin


multitime:
	@rm -f random.bin.gz
	multitime $(PARAMS) wasmtime --dir . --wasm-features=threads --wasi-modules=experimental-wasi-threads src/pigz/pigz.wasm -- -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > clang-wasmtime.time
	
	@rm -f random.bin.gz
	#multitime $(PARAMS) iwasm --dir=. --max-threads=$(NUM_THREADS) src/pigz/pigz.wasm -k -p $(NUM_THREADS) 2>&1 | sed '1,2d' > clang-wamr.time

strace:
	
	#strace $(PARAMS) wasmtime clang.wasm 2>&1 | sed '1,2d' > clang-wasmtime.strace
	

clean:
	rm -rf src
	rm -f random.bin
	rm -f random.bin.gz
	rm -f *.time
	rm -f *.strace


