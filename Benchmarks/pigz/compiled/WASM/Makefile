compile:
	mkdir src
	git clone --recurse-submodules https://github.com/bytecodealliance/wasm-parallel-gzip src
	make -C src
	head -c 1000M </dev/urandom > random.bin


multitime:
	multitime $(PARAMS) wasmtime --dir . --wasm-features=threads --wasi-modules=experimental-wasi-threads src/pigz/pigz.wasm -- -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > clang-wasmtime.time
	@rm -f random.bin.gz
	
	multitime $(PARAMS) iwasm --dir=. --max-threads=$(shell echo ${NUM_THREADS}+1 | bc) src/pigz/pigz.wasm -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > clang-wamr.time
	@rm -f random.bin.gz

strace:
	strace $(PARAMS) wasmtime --dir . --wasm-features=threads --wasi-modules=experimental-wasi-threads src/pigz/pigz.wasm -- -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > clang-wasmtime.strace
	@rm -f random.bin.gz
	
	strace $(PARAMS) iwasm --dir=. --max-threads=$(shell echo ${NUM_THREADS}+1 | bc) src/pigz/pigz.wasm -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > clang-wamr.strace
	@rm -f random.bin.gz
	

clean:
	rm -rf src
	rm -f random.bin
	rm -f random.bin.gz
	rm -f *.time
	rm -f *.strace


