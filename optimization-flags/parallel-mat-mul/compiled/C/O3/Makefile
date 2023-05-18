compile:
	gcc ../../../benchmark.c -o benchmark -D$(SIZE)_DATASET -O3

multitime:
	multitime $(PARAMS) ./benchmark $(NUM_THREADS) 2>&1 | sed '1,2d' > c.time
	#time ./benchmark $(THREADS)

strace:
	strace $(PARAMS) ./benchmark $(NUM_THREADS) 2> c.strace


