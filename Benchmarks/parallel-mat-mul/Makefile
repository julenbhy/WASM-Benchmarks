compile:
	make -C compiled/C -e SIZE=MEDIUM
	make -C compiled/WASM -e SIZE=MEDIUM


NUM_THREADS=16
run:
	make -C compiled/C multitime -e PARAMS="-q -n 10" NUM_THREADS=$(NUM_THREADS)
	make -C compiled/C strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	
	make -C compiled/WASM multitime -e PARAMS="-q -n 10" NUM_THREADS=$(NUM_THREADS)
	make -C compiled/WASM strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)


clean:
	find . -name 'benchmark' -delete
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	find . -name '*.txt' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete
