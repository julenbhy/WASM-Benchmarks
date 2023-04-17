c:
	gcc -O3 benchmark.c -o compiled/C/benchmark

wasm:
	emcc benchmark.c -o compiled/WASM/benchmark.wasm -O2 -s WASM=1
	
js:
	emcc benchmark.c -o compiled/WASM+JS/benchmark.js -O2 -s WASM=1

docker_c:
	cp compiled/C/benchmark compiled/Docker+C/
	docker build -t docker_c compiled/Docker+C/

docker_runtime:
	cp compiled/WASM/benchmark.wasm compiled/Docker+runtime/
	docker build -t docker_runtime compiled/Docker+runtime/

docker_wasm:
	cp compiled/WASM/benchmark.wasm compiled/Docker+WASM/
	docker buildx build --platform wasi/wasm32 -t docker_wasm compiled/Docker+WASM/

	
	
compileall:
	make c
	make wasm
	make js
	
createcontainers:
	make docker_c
	make docker_runtime
	make docker_wasm

clean:
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	#find . -name '.txt' -delete
	
cleancontainers:
	docker rmi docker_c
	docker rmi docker_runtime
	docker rmi docker_wasm

N_RUNS = 10
RUNTIME = wasmtime
#RUNTIME = wasmedge
TIME_OUT=time
multitimeall:
	multitime -q -n $(N_RUNS) ./compiled/C/benchmark 2>&1 | sed '1,2d' > ./compiled/C/$(TIME_OUT).txt

	multitime -q -n $(N_RUNS) $(RUNTIME) ./compiled/WASM/benchmark.wasm 2>&1 | sed '1,2d' > ./compiled/WASM/$(TIME_OUT).txt
	
	multitime -q -n $(N_RUNS) node ./compiled/WASM+JS/benchmark.js 2>&1 | sed '1,2d' > ./compiled/WASM+JS/$(TIME_OUT).txt

	multitime -q -n $(N_RUNS) docker run --rm docker_c 2>&1 | sed '1,2d' > ./compiled/Docker+C/$(TIME_OUT).txt
	
	multitime -q -n $(N_RUNS) docker run --rm docker_runtime 2>&1 | sed '1,2d' > ./compiled/Docker+runtime/$(TIME_OUT).txt

	multitime -q -n $(N_RUNS) docker run --rm --runtime=io.containerd.wasmedge.v1 --platform=wasi/wasm32 docker_wasm \
	 2>&1 | sed '1,2d' > ./compiled/Docker+WASM/$(TIME_OUT).txt
	 

STRACE_PARAMS=		#-c for summary
STRACE_OUT=strace
straceall:
	strace $(STRACE_PARAMS) ./compiled/C/benchmark 2> ./compiled/C/$(STRACE_OUT).txt
	
	strace $(STRACE_PARAMS) $(RUNTIME) ./compiled/WASM/benchmark.wasm 2> ./compiled/WASM/$(STRACE_OUT).txt
	
	strace $(STRACE_PARAMS) node ./compiled/WASM+JS/benchmark.js 2> ./compiled/WASM+JS/$(STRACE_OUT).txt
	
	strace $(STRACE_PARAMS) docker run --rm docker_c 2> ./compiled/Docker+C/$(STRACE_OUT).txt
	
	strace $(STRACE_PARAMS) docker run --rm docker_runtime 2> ./compiled/Docker+runtime/$(STRACE_OUT).txt
	
	strace $(STRACE_PARAMS) docker run --rm --runtime=io.containerd.wasmedge.v1 --platform=wasi/wasm32 docker_wasm \
	  2> ./compiled/Docker+WASM/$(STRACE_OUT).txt


