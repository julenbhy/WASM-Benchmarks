# On the Runtime and Energy Performance of WebAssembly
#### Checking Energy Consumption and Runtime Performance between WebAssembly, JavaScript (asm.js) and C, using 10 microbenchmarks as case study.

source code from: https://github.com/greensoftwarelab/WasmBenchmarks

### What is this?

This repo contains the source code of 10 distinct benchmarks, implemented in WebAssembly, JavaScript and C. Using Emscripten as a compiler, WebAssembly and Javascript were generated from a C source code.

### How is it structured and hows does it work?

This framework follows a specific folder structure, which guarantees the correct workflow when the goal is to perform and operation for all benchmarks.
Moreover, it must be defined, for each benchmark, how to perform the operations considered.

Next, we explain the folder structure and how to specify, for each language benchmark, the execution of each operation.

#### The Structure
The main folder contains 4 elements: 
1. A `Benchmarks` sub-folder, containing a folder for each microbenchmark.


Basically, the directories tree will look something like this:

```Java
| Benchmarks
	| <Benchmark-1>
		| Large_dataset
			| C
				| benchmark
			| WASM+JS
				| benchmark.js
				| benchmark.wasm
			| WASM
				| benchmark.wasm
			| Docker+C
				| benchmark
				| Dockerfile
			| Docker+Runtime
				| benchmark.wasm
				| Dockerfile
			| Docker+wASM
				| benchmark.wasm
				| Dockerfile
		| Medium_dataset
			| ...
		| Small_dataset
			| ...
		benchmark.c
		datasets.h
		inputgen.c
		Makefile
	| ...
	| <Benchmark-10>
	| ExampleFolder
| bench.ipynb


```



