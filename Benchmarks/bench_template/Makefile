c:
	gcc -O3 hello_world.c -o compiled/C/benchmark

wasm:
	emcc hello_world.c -o compiled/WASM/benchmark.wasm -O2 -s WASM=1
	
js:
	emcc hello_world.c -o compiled/WASM+JS/benchmark.js -O2 -s WASM=1

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
	find . -name 'time.txt' -delete
	
cleancontainers:
	docker rmi docker_c
	docker rmi docker_runtime
	docker rmi docker_wasm

N_RUNS = 4
RUNTIME = wasmtime
#RUNTIME = wasmedge
multitimeall:
	multitime -q -n $(N_RUNS) ./compiled/C/benchmark 2>&1 | sed '1,2d' > ./compiled/C/time.txt

	multitime -q -n $(N_RUNS) $(RUNTIME) ./compiled/WASM/benchmark.wasm 2>&1 | sed '1,2d' > ./compiled/WASM/time.txt
	
	multitime -q -n $(N_RUNS) node ./compiled/WASM+JS/benchmark.js 2>&1 | sed '1,2d' > ./compiled/WASM+JS/time.txt

	multitime -q -n $(N_RUNS) docker run --rm docker_c 2>&1 | sed '1,2d' > ./compiled/Docker+C/time.txt
	
	multitime -q -n $(N_RUNS) docker run --rm docker_runtime 2>&1 | sed '1,2d' > ./compiled/Docker+runtime/time.txt

	multitime -q -n $(N_RUNS) docker run --rm --runtime=io.containerd.wasmedge.v1 --platform=wasi/wasm32 docker_wasm \
	 2>&1 | sed '1,2d' > ./compiled/Docker+WASM/time.txt
	 
straceall:
	strace -c ./compiled/C/benchmark 2> ./compiled/C/strace.txt
	
	strace -c $(RUNTIME) ./compiled/WASM/benchmark.wasm 2> ./compiled/WASM/strace.txt
	
	strace -c node ./compiled/WASM+JS/benchmark.js 2> ./compiled/WASM+JS/strace.txt
	
	strace -c docker run --rm docker_c 2> ./compiled/Docker+C/strace.txt
	
	strace -c docker run --rm docker_runtime 2> ./compiled/Docker+runtime/strace.txt
	
	strace -c docker run --rm --runtime=io.containerd.wasmedge.v1 --platform=wasi/wasm32 docker_wasm \
	  2> ./compiled/Docker+WASM/strace.txt


