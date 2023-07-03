# WebAssembly execution model comparison
#### Benchmarking Runtime performance and system calls between C, WebAssembly and containers, using multiple benchmarks and dataset sizes.
#### The result have been obtained with an i7-1260p with 32GB DDR5 ram and NVMe storage.

## Structure
 
```
| Benchmarks
	| deriche
	| fasta
	| floyd-warshall
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

#### [deriche:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/deriche) 
&nbsp;&nbsp;&nbsp;&nbsp;The Deriche algorithm is a well-known image processing algorithm used for edge detection and image filtering. It is specifically designed to efficiently compute the gradient and other image derivatives. The algorithm utilizes recursive filters that allow for real-time processing of images by minimizing the number of calculations required.

The Deriche algorithm is computationally intensive, as it involves convolutions and recursive calculations on image data. It utilizes resources such as memory for storing intermediate results and the processor for performing the calculations. However, its efficiency and effectiveness in detecting edges and enhancing image features make it a popular choice in various computer vision applications.

#### [fasta:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/fasta) 
&nbsp;&nbsp;&nbsp;&nbsp;FASTA is a popular algorithm for sequence alignment in bioinformatics. It compares a query sequence to a database of reference sequences to find similarities. It utilizes heuristics and indexing techniques for efficient alignment. Computational resources used depend on the size of the query and reference database, with pairwise sequence comparisons being the most resource-intensive part. Various optimizations have been implemented to enhance efficiency and scalability.

#### [floyd-warshall:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/floyd-warshall) 
&nbsp;&nbsp;&nbsp;&nbsp;The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph. It iteratively updates the shortest distances between vertices by considering all possible intermediate vertices. The algorithm has a time complexity of O(V^3), where V is the number of vertices in the graph. In terms of resource utilization, it requires a 2D matrix to store the distance values between vertices, and it is computationally intensive due to its nested loops for iterations.

#### [nussinov:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/nussinov) 
&nbsp;&nbsp;&nbsp;&nbsp;The Nussinov algorithm is a dynamic programming algorithm used for RNA secondary structure prediction. It aims to find the most likely base pairings within an RNA sequence by maximizing the number of base pairs while maintaining stability. It utilizes a dynamic programming matrix to compute the optimal base pairings and predict the secondary structure.

#### [parallel-mat-mul:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/parallel-mat-mul) 
&nbsp;&nbsp;&nbsp;&nbsp;The parallel matrix multiplication algorithm...

#### [pigz:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/pigz) 
&nbsp;&nbsp;&nbsp;&nbsp;Pigz is a parallel implementation of the gzip compression algorithm. It is designed to take advantage of multiple processor cores and parallelize the compression or decompression process. By dividing the data into chunks and compressing or decompressing them simultaneously, Pigz can significantly improve the speed of compression or decompression compared to traditional gzip.

Pigz utilizes multiple threads to distribute the workload across available CPU cores, making it suitable for modern multi-core systems. It offers similar compression ratios to gzip but achieves faster processing times by leveraging parallel processing. However, the increased speed comes at the cost of higher CPU usage and potentially higher memory requirements, as multiple threads are utilized simultaneously. Overall, Pigz provides a balance between compression efficiency and faster execution through parallelization.

#### [quicksort:](https://github.com/julenbhy/WASM-Benchmarks/tree/main/Benchmarks/parallel-mat-mul) 
&nbsp;&nbsp;&nbsp;&nbsp;Quicksort is a widely used sorting algorithm that follows the divide-and-conquer approach. It works by selecting a pivot element from the array and partitioning the other elements into two sub-arrays, one containing elements smaller than the pivot and the other containing elements larger than the pivot. The process is recursively applied to the sub-arrays until the entire array is sorted.

Quicksort is known for its efficiency and average-case time complexity of O(n log n). However, in the worst-case scenario, it can have a time complexity of O(n^2) if the chosen pivot consistently results in highly unbalanced partitions. The algorithm performs in-place sorting, meaning it does not require additional memory beyond the original array. Quicksort heavily relies on comparison operations between elements and swaps, making it efficient in terms of computational resources such as memory and processing power.

&nbsp;&nbsp;&nbsp;&nbsp;Some of the benchmarks have multiple input sizes to choose from.



## Results

| clang     | Deriche | Fasta  | Floyd-warshall | Nussinov  | parallel-mat-mul | pigz   | quicksort |
| --------- | ------- | ------ | -------------- | --------- | ---------------- | ------ | --------- |
| C         | 0.251   | 0.274  | 0.197     	| 0.043     | 0.081            | 3.639  | 0.071	    | 
| Wasmtime  | 0.268   | 0.439  | 0.274   	| 0.048     | 0.254            | 4.232  | 0.130	    | 
| Wasmedge  | 24.242  | 45.023 | 65.716    	| 17.995    | X                | X      | 9.493	    | 
| Wamr	    | 4.682   | 3.707  | 8.411   	| 3.095     | 6.987            | 63.834 | 0.947	    | 

parallel-mat-mul and pigz are tested with 8 threads


| emcc      | Deriche | Fasta  | Floyd-warshall | Nussinov  | parallel-mat-mul | pigz   | quicksort |
| --------- | ------- | ------ | -------------- | --------- | ---------------- | ------ | --------- |
| C         | 0.251   | 0.274  | 0.197     	| 0.043     | 0.081            | 3.639  | 0.071	    | 
| Wasmtime  | 0.275   | 0.437  | 0.281     	| 0.051     | X                | X      | 0.131	    | 
| Wasmedge  | 24.117  | 48.803 | 63.603    	| 18.525    | X                | X      | 9.637	    | 
| Wamr	    | 4.440   | 3.590  | 8.406   	| 3.123     | X                | X      | 0.495	    | 

emcc doesn't implement thread support for standalone wasm modules


## Used sofware

wasi-sdk-20

emscripten 3.1.5

wasmtime-cli 8.0.1

wasmedge 0.12.1

wamr(iwasm) 1.2.1
