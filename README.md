# WebAssembly execution model comparison
#### Benchmarking Runtime performance and system calls between C, WebAssembly and containers, using multiple benchmarks and dataset sizes.
#### The result have been obtained with an i7-1260p with 32GB DDR5 ram and NVMe storage.

## Structure

```
| Benchmarks
	| bench_template
		benchmark.c
		Makefile
		time_plots.ipynb
		| compiled
			| C
				| benchmark
				| time.txt
				| strace.txt
			| WASM+JS
				| benchmark.js
				| benchmark.wasm
				| time.txt
				| strace.txt
			| WASM
				| benchmark.wasm
				| time.txt
				| strace.txt
			| Docker+C
				| benchmark
				| Dockerfile
				| time.txt
				| strace.txt
			| Docker+runtime
				| benchmark.wasm
				| Dockerfile
				| time.txt
				| strace.txt
			| Docker+WASM
				| benchmark.wasm
				| Dockerfile
				| time.txt
				| strace.txt
		
	| Caesar-cipher
		caesar-cipher.c
		datasets.h
		inputgen.c
		Makefile
		time_plots.ipynb
		| Large_dataset
			| C
				| ...
			| WASM+JS
				| ...
			| WASM
				| ...
			| Docker+C
				| ...
			| Docker+runtime
				| ...
			| Docker+WASM
				| ..
		| Medium_dataset
			| ...
		| Small_dataset
			| ...
		
	| ...
	| <Benchmark-n>
README.md

```

## How to run

Each benchmark has its own Makefile. Use this Makefile to prepare and run all the execution models
  + 1st **make compileall**	to compile c.wasm and .js modules
  + 2nd **make createcontainers**	to create all the containers
  + 3rd **make multitimeall**	to measure the runtime of all models. Will generate time.txt for each execution model
  + 4th **make straceall**	to measure the system calls of all models. Will generate strace.txt for each execution model
	

## Execution models
#### C: 
&nbsp;&nbsp;&nbsp;&nbsp;C compiled code.

#### WASM:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using emscripten and executed with wasmtime.

#### WASM+JS:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm  and .js glue code using emscripten and executed with node.

#### Docker+C:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled and runned inside a container (from Ubuntu base image).

#### Docker+runtime:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using emscripten and executed with wasmtime inside a container (from Ubuntu base image).

#### Docker+WASM:
&nbsp;&nbsp;&nbsp;&nbsp;C code compiled to .wasm using emscripten and executed with wasmtime inside a container (using [Docker+Wasm Beta integration](https://www.docker.com/blog/announcing-dockerwasm-technical-preview-2/)).


## Benchmarks
#### [bench_template:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/bench_template)
&nbsp;&nbsp;&nbsp;&nbsp;Template for new benchmarks. Contains a hello_world benchmark.

#### [Caesar-cipher:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/Caesar-cipher) 
&nbsp;&nbsp;&nbsp;&nbsp;The Caesar cipher is an ancient cipher which is made by shifting the letters of the alphabet by a set number. So a shift of -3, for example, would move each letter to the left by 3, such that A would become X and D would become A. For this package it also includes numbers and punctuation but the concept is the same.

&nbsp;&nbsp;&nbsp;&nbsp;This benchmark has 3 different sizes available. Code from: https://github.com/greensoftwarelab/WasmBenchmarks


