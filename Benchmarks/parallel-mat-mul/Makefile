compile:
	$(MAKE) -C compiled/C -e SIZE=MEDIUM
	$(MAKE) -C compiled/WASM -e SIZE=MEDIUM


NUM_THREADS=16
run:
	$(MAKE) -C compiled/C multitime -e PARAMS="-q -n 10" THREADS=$(NUM_THREADS)
	$(MAKE) -C compiled/C strace -e PARAMS="-C -r" THREADS=$(NUM_THREADS)
	
	$(MAKE) -C compiled/WASM multitime -e PARAMS="-q -n 10" THREADS=$(NUM_THREADS)
	$(MAKE) -C compiled/WASM strace -e PARAMS="-C -r" THREADS=$(NUM_THREADS)


clean:
	find . -name 'benchmark' -delete
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	find . -name '*.txt' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete
