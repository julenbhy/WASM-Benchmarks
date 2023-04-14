csmall:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 caesar-cipher.c -o Small_dataset/C/benchmark -lapr-1 -lgomp -lm -DSMALL_DATASET


cmedium:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 caesar-cipher.c -o Medium_dataset/C/benchmark -lapr-1 -lgomp -lm -DMEDIUM_DATASET

clarge:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 caesar-cipher.c -o Large_dataset/C/benchmark -lapr-1 -lgomp -lm -DLARGE_DATASET

wasmsmall:
	emcc caesar-cipher.c -DSMALL_DATASET -o Small_dataset/WASM/benchmark.wasm -O2 -s WASM=1
	
wasmmedium:
	emcc caesar-cipher.c -DMEDIUM_DATASET -o Medium_dataset/WASM/benchmark.wasm -O2 -s WASM=1
	
wasmlarge:
	emcc caesar-cipher.c -DLARGE_DATASET -o Large_dataset/WASM/benchmark.wasm -O2 -s WASM=1
	
jssmall:
	emcc caesar-cipher.c -DSMALL_DATASET -o Small_dataset/WASM+JS/benchmark.js -O2 -s WASM=1

jsmedium:
	emcc caesar-cipher.c -DMEDIUM_DATASET -o Medium_dataset/WASM+JS/benchmark.js -O2 -s WASM=1
	
jslarge:
	emcc caesar-cipher.c -DLARGE_DATASET -o Large_dataset/WASM+JS/benchmark.js -O2 -s WASM=1
	
small_docker_c:
	cp Small_dataset/C/benchmark Small_dataset/Docker+C/
	docker build -t small_docker_c Small_dataset/Docker+C/

medium_docker_c:
	cp Medium_dataset/C/benchmark Medium_dataset/Docker+C/
	docker build -t medium_docker_c Medium_dataset/Docker+C/
	
large_docker_c:
	cp Large_dataset/C/benchmark Large_dataset/Docker+C/
	docker build -t large_docker_c Large_dataset/Docker+C/

small_docker_runtime:
	cp Small_dataset/WASM/benchmark.wasm Small_dataset/Docker+runtime/
	docker build -t small_docker_runtime Small_dataset/Docker+runtime/

medium_docker_runtime:
	cp Medium_dataset/WASM/benchmark.wasm Medium_dataset/Docker+runtime/
	docker build -t medium_docker_runtime Medium_dataset/Docker+runtime/
	
large_docker_runtime:
	cp Large_dataset/WASM/benchmark.wasm Large_dataset/Docker+runtime/
	docker build -t large_docker_runtime Large_dataset/Docker+runtime/
	
small_docker_wasm:
	cp Small_dataset/WASM/benchmark.wasm Small_dataset/Docker+WASM/
	docker buildx build --platform wasi/wasm32 -t small_docker_wasm Small_dataset/Docker+WASM/

medium_docker_wasm:
	cp Medium_dataset/WASM/benchmark.wasm Medium_dataset/Docker+WASM/
	docker buildx build --platform wasi/wasm32 -t medium_docker_wasm Medium_dataset/Docker+WASM/
	
large_docker_wasm:
	cp Large_dataset/WASM/benchmark.wasm Large_dataset/Docker+WASM/
	docker buildx build --platform wasi/wasm32 -t large_docker_wasm Large_dataset/Docker+WASM/
	
	
compileall:
	#make csmall
	#make cmedium
	#make clarge
	make wasmsmall
	make wasmmedium
	make wasmlarge
	make jssmall
	make jsmedium
	make jslarge
	
createcontainers:
	make small_docker_c
	make medium_docker_c
	make large_docker_c
	make small_docker_runtime
	make medium_docker_runtime
	make large_docker_runtime
	make small_docker_wasm
	make medium_docker_wasm
	make large_docker_wasm

clear:
	find . -name '*.wasm' -delete
	find . -name '*.js' -delete
	find . -name 'time.txt' -delete
	
clearcontainers:
	docker rmi small_docker_c
	docker rmi medium_docker_c
	docker rmi large_docker_c
	docker rmi small_docker_runtime
	docker rmi medium_docker_runtime
	docker rmi large_docker_runtime
	docker rmi small_docker_wasm
	docker rmi medium_docker_wasm
	docker rmi large_docker_wasm


runall:
	multitime -q -n 3 ./Small_dataset/C/benchmark 2>&1 | sed '1,2d' > ./Small_dataset/C/time.txt
	multitime -q -n 3 ./Medium_dataset/C/benchmark 2>&1 | sed '1,2d' > ./Medium_dataset/C/time.txt
	multitime -q -n 3 ./Large_dataset/C/benchmark 2>&1 | sed '1,2d' > ./Large_dataset/C/time.txt

	multitime -q -n 3 wasmtime ./Small_dataset/WASM/benchmark.wasm 2>&1 | sed '1,2d' > ./Small_dataset/WASM/time.txt
	
	multitime -q -n 3 wasmtime ./Medium_dataset/WASM/benchmark.wasm 2>&1 | sed '1,2d' > ./Medium_dataset/WASM/time.txt
	 
	multitime -q -n 3 wasmtime ./Large_dataset/WASM/benchmark.wasm 2>&1 | sed '1,2d' > ./Large_dataset/WASM/time.txt
	
	multitime -q -n 3 node ./Small_dataset/WASM+JS/benchmark.js 2>&1 | sed '1,2d' > ./Small_dataset/WASM+JS/time.txt
	multitime -q -n 3 node ./Medium_dataset/WASM+JS/benchmark.js 2>&1 | sed '1,2d' > ./Medium_dataset/WASM+JS/time.txt
	multitime -q -n 3 node ./Large_dataset/WASM+JS/benchmark.js 2>&1 | sed '1,2d' > ./Large_dataset/WASM+JS/time.txt

	multitime -q -n 3 docker run --rm small_docker_c 2>&1 | sed '1,2d' > ./Small_dataset/Docker+C/time.txt
	multitime -q -n 3 docker run --rm medium_docker_c 2>&1 | sed '1,2d' > ./Medium_dataset/Docker+C/time.txt
	multitime -q -n 3 docker run --rm large_docker_c 2>&1 | sed '1,2d' > ./Large_dataset/Docker+C/time.txt
	
	multitime -q -n 3 docker run --rm small_docker_runtime 2>&1 | sed '1,2d' > ./Small_dataset/Docker+runtime/time.txt
	multitime -q -n 3 docker run --rm medium_docker_runtime 2>&1 | sed '1,2d' > ./Medium_dataset/Docker+runtime/time.txt
	multitime -q -n 3 docker run --rm large_docker_runtime 2>&1 | sed '1,2d' > ./Large_dataset/Docker+runtime/time.txt

	multitime -q -n 3 docker run --rm --runtime=io.containerd.wasmedge.v1 --platform=wasi/wasm32 small_docker_wasm \
	 2>&1 | sed '1,2d' > ./Small_dataset/Docker+WASM/time.txt
	multitime -q -n 3 docker run --rm --runtime=io.containerd.wasmedge.v1 --platform=wasi/wasm32 medium_docker_wasm \
	 2>&1 | sed '1,2d' > ./Medium_dataset/Docker+WASM/time.txt
	multitime -q -n 3 docker run --rm --runtime=io.containerd.wasmedge.v1 --platform=wasi/wasm32 large_docker_wasm \
	 2>&1 | sed '1,2d' > ./Large_dataset/Docker+WASM/time.txt

