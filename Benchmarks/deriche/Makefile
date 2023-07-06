# -MINI: Less than 16KB of memory. The problem may fit within the L1 (last level) cache.
# -SMALL: Around 128KB of memory. The problem should not fit within the L1 cache, but may fit L2.
# -MEDIUM: Around 1MB of memory. The problem should not fit within the L2 cache, but may fit L3.
# -LARGE: Around 25MB of memory. The problem should not fit within the L3 cache.
# -EXTRALARGE: Around 120MB of memory.
# -DPOLYBENCH_TIME, to report the execution time


SIZE?=LARGE
TARGET=benchmark

# Compilation with gcc
CC=gcc
CFLAGS=-I ./utilities ./utilities/polybench.c -lm -O3

# Compilation with wasi-sdk/clang
CLANG_CC=/opt/wasi-sdk/bin/clang
CLANG_CFLAGS=-I ./utilities ./utilities/polybench.c -O3 -D_WASI_EMULATED_PROCESS_CLOCKS


# Compilation with wasi-sdk/clang
EMCC_CC=emcc
EMCC_CFLAGS=-I ./utilities ./utilities/polybench.c -O3 -s TOTAL_MEMORY=256MB

all: $(TARGET) $(TARGET)32 clang.wasm emcc.wasm

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o ./compiled/C/$@ $(TARGET).c -D$(SIZE)_DATASET
	
$(TARGET)32: $(TARGET).c
	$(CC) -m32 $(CFLAGS) -o ./compiled/C/$@ $(TARGET).c -D$(SIZE)_DATASET
	
clang.wasm: $(TARGET).c
	$(CLANG_CC) $(CLANG_CFLAGS) -o ./compiled/WASM/$@ $(TARGET).c -D$(SIZE)_DATASET 

emcc.wasm: $(TARGET).c
	$(EMCC_CC) $(EMCC_CFLAGS) -o ./compiled/WASM/$@ $(TARGET).c -D$(SIZE)_DATASET
	






COMPILERS=clang emcc
RUNTIMES=wasmtime wasmedge iwasm

PARAMS_MULTITIME=-q -n 10
multitime: $(TARGET) $(TARGET)32 clang.wasm emcc.wasm
	# run c
	multitime $(PARAMS_MULTITIME) ./compiled/C/$(TARGET) 2>&1 | sed '1,2d' > ./compiled/C/c.time;
	multitime $(PARAMS_MULTITIME) ./compiled/C/$(TARGET)32 2>&1 | sed '1,2d' > ./compiled/C/c32.time;
	
	# run wasm compiler and runtime combinations
	$(foreach runtime,$(RUNTIMES),\
		$(foreach compiler,$(COMPILERS),\
			multitime $(PARAMS_MULTITIME) $(runtime) ./compiled/WASM/$(compiler).wasm 2>&1 | sed '1,2d' > ./compiled/WASM/$(compiler)-$(runtime).time;\
		)\
	)
	
	jupyter nbconvert --execute time_plots.ipynb --to notebook --inplace




PARAMS_STRACE=-C -r
strace: $(TARGET) $(TARGET)32 clang.wasm emcc.wasm
	# run c
	strace $(PARAMS_STRACE) ./compiled/C/$(TARGET) 2>&1 | sed '1,2d' > ./compiled/C/c.strace;
	strace $(PARAMS_STRACE) ./compiled/C/$(TARGET)32 2>&1 | sed '1,2d' > ./compiled/C/c32.strace;
	
	# run wasm compiler and runtime combinations
	$(foreach runtime,$(RUNTIMES),\
		$(foreach compiler,$(COMPILERS),\
			strace $(PARAMS_STRACE) $(runtime) ./compiled/WASM/$(compiler).wasm 2>&1 | sed '1,2d' > ./compiled/WASM/$(compiler)-$(runtime).strace;\
		)\
	)





clean:
	find . -name $(TARGET) -delete
	find . -name $(TARGET)32 -delete
	find . -name '*.wasm' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete
