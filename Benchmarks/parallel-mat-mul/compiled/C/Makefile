compile:
	gcc -O3 ../../benchmark.c -o benchmark -D$(SIZE)_DATASET

multitime:
	multitime $(PARAMS) ./benchmark $(THREADS) 2>&1 | sed '1,2d' > c.time
	#time ./benchmark $(THREADS)

strace:
	strace $(PARAMS) ./benchmark $(THREADS) 2> c.strace


