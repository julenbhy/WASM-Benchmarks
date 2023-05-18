# -MINI: Less than 16KB of memory. The problem may fit within the L1 (last level) cache.
# -SMALL: Around 128KB of memory. The problem should not fit within the L1 cache, but may fit L2.
# -MEDIUM: Around 1MB of memory. The problem should not fit within the L2 cache, but may fit L3.
# -LARGE: Around 25MB of memory. The problem should not fit within the L3 cache.
# -EXTRALARGE: Around 120MB of memory.
# -DPOLYBENCH_TIME, to report the execution time


SIZE ?= MEDIUM
compile:
	make -C compiled/C -e SIZE=$(SIZE)
	make -C compiled/WASM -e SIZE=$(SIZE)


run:	
	make -C compiled/C run
	
	make -C compiled/WASM run


	
clean:
	find . -name 'benchmark' -delete
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	find . -name '*.txt' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete


