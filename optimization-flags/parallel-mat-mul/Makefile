SIZE ?= MEDIUM
compile:
	make -C compiled/C -e SIZE=$(SIZE)
	make -C compiled/WASM -e SIZE=$(SIZE)


NUM_THREADS=8
run:
	make -C compiled/C run -e NUM_THREADS=$(NUM_THREADS)
	
	make -C compiled/WASM run -e NUM_THREADS=$(NUM_THREADS)


clean:
	find . -name 'benchmark' -delete
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	find . -name '*.txt' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete
