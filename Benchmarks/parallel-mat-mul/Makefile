SIZE?=LARGE
TARGET=benchmark

# Compilation with gcc
CC=gcc
CFLAGS=-O3

# Compilation with wasi-sdk/clang
CLANG_CC=/opt/wasi-sdk/bin/clang
CLANG_CFLAGS=-O3 --target=wasm32-wasi-threads -pthread -Wl,--import-memory,--export-memory,--max-memory=3221225472


# Compilation with wasi-sdk/clang
EMCC_CC=emcc
EMCC_CFLAGS=-O3

all: $(TARGET) $(TARGET)32 clang.wasm

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o ./compiled/C/$@ $(TARGET).c -D$(SIZE)_DATASET
	
$(TARGET)32: $(TARGET).c
	$(CC) -m32 $(CFLAGS) -o ./compiled/C/$@ $(TARGET).c -D$(SIZE)_DATASET
	
clang.wasm: $(TARGET).c
	$(CLANG_CC) $(CLANG_CFLAGS) -o ./compiled/WASM/$@ $(TARGET).c -D$(SIZE)_DATASET 

emcc.wasm: $(TARGET).c
	$(EMCC_CC) $(EMCC_CFLAGS) -o ./compiled/WASM/$@ $(TARGET).c -D$(SIZE)_DATASET
	




NUM_THREADS=8

#emcc and wasmedge currently don't support threads

WT_FLAGS = --wasm-features=threads --wasi-modules=experimental-wasi-threads

PARAMS_MULTITIME=-q -n 10
multitime: $(TARGET) $(TARGET)32 clang.wasm
	# run c
	multitime $(PARAMS_MULTITIME) ./compiled/C/$(TARGET) $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/C/c.time;
	multitime $(PARAMS_MULTITIME) ./compiled/C/$(TARGET)32 $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/C/c32.time;
	
	# run wasm compiler and runtime combinations
	multitime $(PARAMS_MULTITIME) wasmtime $(WT_FLAGS) ./compiled/WASM/clang.wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/WASM/clang-wasmtime.time;
	
	multitime $(PARAMS_MULTITIME) iwasm --max-threads=$(NUM_THREADS) ./compiled/WASM/clang.wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/WASM/clang-iwasm.time;
	
	jupyter nbconvert --execute time_plots.ipynb --to notebook --inplace




PARAMS_STRACE=-C -r
strace: $(TARGET) $(TARGET)32 clang.wasm
	# run c
	strace $(PARAMS_STRACE) ./compiled/C/$(TARGET) $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/C/c.strace;
	strace $(PARAMS_STRACE) ./compiled/C/$(TARGET)32 $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/C/c32.strace;
	
	# run wasm compiler and runtime combinations
	strace $(PARAMS_STRACE) wasmtime $(WT_FLAGS) ./compiled/WASM/$(compiler).wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/WASM/$(compiler)-$(runtime).strace;
	
	strace $(PARAMS_STRACE) iwasm --max-threads=$(NUM_THREADS) ./compiled/WASM/clang.wasm $(NUM_THREADS) 2>&1 | sed '1,2d' > ./compiled/WASM/clang-iwasm.time;




clean:
	find . -name $(TARGET) -delete
	find . -name $(TARGET)32 -delete
	find . -name '*.wasm' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete
