compile:
	gcc -O3 ../../benchmark.c -D$(SIZE)_DATASET -O3 -o benchmark

multitime:
	multitime $(PARAMS) ./benchmark $(NUM_THREADS) 2>&1 | sed '1,2d' > c.time
	#time ./benchmark $(THREADS)

strace:
	strace $(PARAMS) ./benchmark $(NUM_THREADS) 2> c.strace


