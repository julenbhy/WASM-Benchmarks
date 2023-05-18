compile:
	gcc ../../benchmark.c -I ../../utilities ../../utilities/polybench.c -D$(SIZE)_DATASET -O3 -o benchmark


PARAMS?=-q -n 1
multitime:
	multitime $(PARAMS) ./benchmark 2>&1 | sed '1,2d' > c.time


strace:
	strace $(PARAMS) ./benchmark 2>&1 | sed '1,2d' > c.strace



