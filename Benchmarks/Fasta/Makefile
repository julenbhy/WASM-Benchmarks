smallcompile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  fasta.gcc-2.c -o Small_dataset/C/fasta.gcc-2.gcc_runSMALL -DSMALL_DATASET

mediumcompile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  fasta.gcc-2.c -o Medium_dataset/C/fasta.gcc-2.gcc_runMEDIUM -DMEDIUM_DATASET

largecompile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  fasta.gcc-2.c -o Large_dataset/C/fasta.gcc-2.gcc_runLARGE -DLARGE_DATASET

wasmsmall:
	emcc fasta.gcc-2.c -DSMALL_DATASET -o Small_dataset/WASM/fasta.gcc-2.gcc_runSMALL.wasm -O2 -s WASM=1

jssmall:
	emcc fasta.gcc-2.c -DSMALL_DATASET -o Small_dataset/WASM+JS/fasta.gcc-2.gcc_runSMALL.js -O2 -s WASM=1

wasmmedium:
	emcc fasta.gcc-2.c -DMEDIUM_DATASET -o Medium_dataset/WASM/fasta.gcc-2.gcc_runMEDIUM.wasm -O2 -s WASM=1

jsmedium:
	emcc fasta.gcc-2.c -DMEDIUM_DATASET -o Medium_dataset/WASM+JS/fasta.gcc-2.gcc_runMEDIUM.js -O2 -s WASM=1

wasmlarge:
	emcc fasta.gcc-2.c -DLARGE_DATASET -o Large_dataset/WASM/fasta.gcc-2.gcc_runLARGE.wasm -O2 -s WASM=1

jslarge:
	emcc fasta.gcc-2.c -DLARGE_DATASET -o Large_dataset/WASM+JS/fasta.gcc-2.gcc_runLARGE.js -O2 -s WASM=1

compileall:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  fasta.gcc-2.c -o Small_dataset/C/fasta.gcc-2.gcc_runSMALL -DSMALL_DATASET
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  fasta.gcc-2.c -o Medium_dataset/C/fasta.gcc-2.gcc_runMEDIUM -DMEDIUM_DATASET
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=ivybridge  fasta.gcc-2.c -o Large_dataset/C/fasta.gcc-2.gcc_runLARGE -DLARGE_DATASET
	emcc fasta.gcc-2.c -DSMALL_DATASET -o Small_dataset/WASM/fasta.gcc-2.gcc_runSMALL.wasm -O2 -s WASM=1
	emcc fasta.gcc-2.c -DSMALL_DATASET -o Small_dataset/WASM+JS/fasta.gcc-2.gcc_runSMALL.js -O2 -s WASM=1
	emcc fasta.gcc-2.c -DMEDIUM_DATASET -o Medium_dataset/WASM/fasta.gcc-2.gcc_runMEDIUM.wasm -O2 -s WASM=1
	emcc fasta.gcc-2.c -DMEDIUM_DATASET -o Medium_dataset/WASM+JS/fasta.gcc-2.gcc_runMEDIUM.js -O2 -s WASM=1
	emcc fasta.gcc-2.c -DLARGE_DATASET -o Large_dataset/WASM/fasta.gcc-2.gcc_runLARGE.wasm -O2 -s WASM=1
	emcc fasta.gcc-2.c -DLARGE_DATASET -o Large_dataset/WASM+JS/fasta.gcc-2.gcc_runLARGE.js -O2 -s WASM=1
