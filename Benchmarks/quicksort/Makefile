compile:
	$(MAKE) -C compiled/C -e SIZE=MEDIUM
	$(MAKE) -C compiled/WASM -e SIZE=MEDIUM


run:
	$(MAKE) -C compiled/C multitime -e PARAMS="-q -n 10"
	$(MAKE) -C compiled/C strace -e PARAMS="-C -r"
	
	$(MAKE) -C compiled/WASM multitime -e PARAMS="-q -n 10"
	$(MAKE) -C compiled/WASM strace -e PARAMS="-C -r"


clean:
	find . -name 'benchmark' -delete
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	find . -name '*.txt' -delete
	find . -name '*.time' -delete
	find . -name '*.strace' -delete
