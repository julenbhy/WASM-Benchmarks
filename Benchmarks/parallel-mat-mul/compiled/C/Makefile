compile:
	gcc -O3 ../../benchmark.c -o benchmark -D$(SIZE)_DATASET

multitime:
	multitime $(PARAMS) ./benchmark 2>&1 | sed '1,2d' > c.time


strace:
	strace $(PARAMS) ./benchmark 2> c.strace


