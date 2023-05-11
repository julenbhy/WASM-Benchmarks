compile:
	mkdir src
	git clone https://github.com/madler/pigz src
	make -C src
	head -c 1000M </dev/urandom > random.bin


multitime:
	multitime $(PARAMS) ./src/pigz -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > c.time
	@rm -f random.bin.gz


strace:
	strace $(PARAMS) ./src/pigz -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > c.strace
	@rm -f random.bin.gz
	
clean:
	rm -rf src
	rm -f random.bin
	rm -f random.bin.gz
	rm -f *.time
