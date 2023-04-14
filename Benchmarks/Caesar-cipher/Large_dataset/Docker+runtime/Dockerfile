FROM ubuntu:latest

# Install Wasmtime
RUN apt-get update && \
    apt-get install -y curl && \
    apt-get install xz-utils && \
    curl https://wasmtime.dev/install.sh -sSf | bash
    

# Copy wasm file to container
COPY benchmark.wasm /app/benchmark.wasm

# Set working directory
WORKDIR /app

# Run the wasm file with Wasmtime
CMD ["/root/.wasmtime/bin/wasmtime", "benchmark.wasm"]

