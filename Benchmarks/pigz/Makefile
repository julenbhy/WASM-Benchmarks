compile:
	make -C compiled/C
	make -C compiled/WASM


NUM_THREADS=8
multitime:
	make -C compiled/C multitime -e PARAMS="-q -n 10" NUM_THREADS=$(NUM_THREADS)	
	make -C compiled/WASM multitime -e PARAMS="-q -n 10" NUM_THREADS=$(NUM_THREADS)
	jupyter nbconvert --execute time_plots.ipynb --to notebook --inplace


	
strace:
	make -C compiled/C strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)
	make -C compiled/WASM strace -e PARAMS="-C -r" NUM_THREADS=$(NUM_THREADS)

clean:
	make -C compiled/C clean
	make -C compiled/WASM clean
