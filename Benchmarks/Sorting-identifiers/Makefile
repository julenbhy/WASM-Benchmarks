smallcompile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  sortingids.c -o Small_dataset/C/sortingids_runSMALL -DSMALL_DATASET

mediumcompile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  sortingids.c -o Medium_dataset/C/sortingids_runMEDIUM -DMEDIUM_DATASET

largecompile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  sortingids.c -o Large_dataset/C/sortingids_runLARGE -DLARGE_DATASET

wasmsmall:
	emcc sortingids.c -DSMALL_DATASET -o Small_dataset/WASM/sortingids_runSMALL.wasm -O2 -s WASM=1

jssmall:
	emcc sortingids.c -DSMALL_DATASET -o Small_dataset/WASM+JS/sortingids_runSMALL.js -O2 -s WASM=1

wasmmedium:
	emcc sortingids.c -DMEDIUM_DATASET -o Medium_dataset/WASM/sortingids_runMEDIUM.wasm -O2 -s WASM=1

jsmedium:
	emcc sortingids.c -DMEDIUM_DATASET -o Medium_dataset/WASM+JS/sortingids_runMEDIUM.js -O2 -s WASM=1

wasmlarge:
	emcc sortingids.c -DLARGE_DATASET -o Large_dataset/WASM/sortingids_runLARGE.wasm -O2 -s WASM=1

jslarge:
	emcc sortingids.c -DLARGE_DATASET -o Large_dataset/WASM+JS/sortingids_runLARGE.js -O2 -s WASM=1

compileall:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  sortingids.c -o Small_dataset/C/sortingids_runSMALL -DSMALL_DATASET
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  sortingids.c -o Medium_dataset/C/sortingids_runMEDIUM -DMEDIUM_DATASET
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  sortingids.c -o Large_dataset/C/sortingids_runLARGE -DLARGE_DATASET
	emcc sortingids.c -DSMALL_DATASET -o Small_dataset/WASM/sortingids_runSMALL.wasm -O2 -s WASM=1
	emcc sortingids.c -DSMALL_DATASET -o Small_dataset/WASM+JS/sortingids_runSMALL.js -O2 -s WASM=1
	emcc sortingids.c -DMEDIUM_DATASET -o Medium_dataset/WASM/sortingids_runMEDIUM.wasm -O2 -s WASM=1
	emcc sortingids.c -DMEDIUM_DATASET -o Medium_dataset/WASM+JS/sortingids_runMEDIUM.js -O2 -s WASM=1
	emcc sortingids.c -DLARGE_DATASET -o Large_dataset/WASM/sortingids_runLARGE.wasm -O2 -s WASM=1
	emcc sortingids.c -DLARGE_DATASET -o Large_dataset/WASM+JS/sortingids_runLARGE.js -O2 -s WASM=1
