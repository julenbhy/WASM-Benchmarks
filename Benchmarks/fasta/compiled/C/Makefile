compile:
	gcc -O3 ../../benchmark.c -D$(SIZE)_DATASET -O3 -o benchmark

multitime:
	multitime $(PARAMS) ./benchmark 2>&1 | sed '1,2d' > c.time


strace:
	strace $(PARAMS) ./benchmark 2>&1 | sed '1,2d' > c.strace
	

