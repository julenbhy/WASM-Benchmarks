SIZE ?= LARGE
compile:
	make -C O0 -e SIZE=$(SIZE)
	make -C O1 -e SIZE=$(SIZE)
	make -C O2 -e SIZE=$(SIZE)
	make -C O3 -e SIZE=$(SIZE)
	make -C Ofast -e SIZE=$(SIZE)
	make -C Oz -e SIZE=$(SIZE)


NUM_THREADS?=8
run:
	make -C O0 multitime -e PARAMS="-q -n 5" NUM_THREADS=$(NUM_THREADS)
	make -C O0 strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	
	make -C O1 multitime -e PARAMS="-q -n 5" NUM_THREADS=$(NUM_THREADS)
	make -C O1 strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	
	make -C O2 multitime -e PARAMS="-q -n 5" NUM_THREADS=$(NUM_THREADS)
	make -C O2 strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	
	make -C O3 multitime -e PARAMS="-q -n 5" NUM_THREADS=$(NUM_THREADS)
	make -C O3 strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	
	make -C Ofast multitime -e PARAMS="-q -n 5" NUM_THREADS=$(NUM_THREADS)
	make -C Ofast strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	
	make -C Oz multitime -e PARAMS="-q -n 5" NUM_THREADS=$(NUM_THREADS)
	make -C Oz strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	


clean:
	find . -name 'benchmark' -delete
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	find . -name '*.txt' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete
