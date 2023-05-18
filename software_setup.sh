#!/bin/bash

apt install make

apt install Cmake

apt install curl

apt install emscripten

#rust installation
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

#wasi-sdk-20 installation
wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-20/wasi-sdk-20.0-linux.tar.gz
tar xvf wasi-sdk-20.0-linux.tar.gz -C /opt/wasi-ask

#wasmtime installation
curl https://wasmtime.dev/install.sh -sSf | bash

#wasmedge installation
curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/install.sh | bash

#wamr installation is taken from the pigz benchmark
make -C ./Benchmarks/pigz/
cp ./Benchmarks/pigz/compiled/WASM/src/wasm-micro-runtime/src/build/iwasm /usr/local/bin/
