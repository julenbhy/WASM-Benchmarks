# WebAssembly execution model comparison
#### Benchmarking Runtime performance and system calls between C, WebAssembly and containers, using multiple benchmarks and dataset sizes.
#### The result have been obtained with an i7-1260p with 32GB DDR5 ram and NVMe storage.

## Structure
 
```
| Benchmarks
	| fasta
	| hello_world
		benchmark.c
		Makefile
		time_plots.ipynb
		| compiled
			| C
				benchmark
				c.time
				c.strace
				Makefile
				
			| WASM
				clang.wasm
				clang-wasmedge.time
				clang-wasmedge.strace
				clang-wasmtime.time
				clang-wasmtime.strace
				
				emcc.wasm
				emcc-wasmedge.time
				emcc-wasmedge.strace
				emcc-wasmtime.time
				emcc-wasmtime.strace
				
				Makefile
		
	| nussinov
	| parallel-mat-mul
	| pigz
	| quicksort
		
	| ...
	| <Benchmark-n>
README.md

```

## How to run

Each benchmark has its own Makefile. Use this Makefile to prepare and run all the execution models
  + 1st **make**	inside each benchmarks main directory, that will prepare the whole benchmark
  + 2nd **make run**		to run multitime and strace on each subdirectory
  + 3rd **run the jupyter to plot the results**	
	

## Execution models
#### C: 
&nbsp;&nbsp;&nbsp;&nbsp;C compiled code.

#### clang-wasmtime:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using WASI-SDK Clang and executed with wasmtime.

#### clang-wasmedge:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using WASI-SDK Clang and executed with wasmtime.

#### clang-wamr:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using WASI-SDK Clang and executed with wamr.

#### emcc-wasmtime:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using emscripten and executed with wasmtime.

#### emcc-wasmedge:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using emscripten and executed with wasmedge.

#### emcc-wamr:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using emscripten and executed with wamr.



## Benchmarks
#### [hello_world:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/hello_world)
&nbsp;&nbsp;&nbsp;&nbsp;Template for new benchmarks. Some benchmarks may not be compatible with some of the compilers or runtimes or may need some modification.

#### [fasta:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/fasta) 
&nbsp;&nbsp;&nbsp;&nbsp;The fasta algorithm...

#### [nussinov:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/nussinov) 
&nbsp;&nbsp;&nbsp;&nbsp;The nussinov algorithm...

#### [parallel-mat-mul:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/parallel-mat-mul) 
&nbsp;&nbsp;&nbsp;&nbsp;The parallel matrix multiplication algorithm...

#### [pigz:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/pigz) 
&nbsp;&nbsp;&nbsp;&nbsp;The pigz (parallel gzip) algorithm...

#### [quicksort:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/parallel-mat-mul) 
&nbsp;&nbsp;&nbsp;&nbsp;The quicksort algorithm...

&nbsp;&nbsp;&nbsp;&nbsp;Some of the benchmarks have multiple input sizes to choose from.



## Results

| clang     | Fasta  | Nussinov  | parallel-mat-mul | pigz   | quicksort |
| --------- | ------ | --------- | ---------------- | ------ | --------- |
| C         | 0.274  | 0.043     | 0.081            | 3.639  | 0.071	| 
| Wasmtime  | 0.439  | 0.048     | 0.254            | 4.232  | 0.130	| 
| Wasmedge  | 45.023 | 17.995    | X                | X      | 9.493	| 
| Wamr	    | 3.707  | 3.095     | 6.987            | 63.834 | 0.947	| 

parallel-mat-mul and pigz are tested with 8 threads


| emcc      | Fasta  | Nussinov  | parallel-mat-mul | pigz   | quicksort |
| --------- | ------ | --------- | ---------------- | ------ | --------- |
| C         | 0.274  | 0.043     | 0.081            | 3.639  | 0.071	| 
| Wasmtime  | 0.437  | 0.051     | X                | X      | 0.131	| 
| Wasmedge  | 48.803 | 18.525    | X                | X      | 9.637	| 
| Wamr	    | 3.590  | 3.123     | X                | X      | 0.495	| 

emcc doesn't implement thread support for standalone wasm modules


## Requirements
curl

make

cmake

rust

wasi-sdk-20 or higher at /opt/wasi-sdk

emscripten

wasmtime

wasmedge

wamr
