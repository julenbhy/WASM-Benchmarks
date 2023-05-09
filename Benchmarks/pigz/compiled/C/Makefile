compile:
	mkdir src
	git clone https://github.com/madler/pigz src
	make -C src
	head -c 1000M </dev/urandom > random.bin


multitime:
	@rm -f random.bin.gz
	multitime $(PARAMS) ./src/pigz -k -p $(NUM_THREADS) random.bin 2>&1 | sed '1,2d' > c.time


strace:
	#strace $(PARAMS) ./benchmark 2>&1 | sed '1,2d' > c.strace
	
clean:
	rm -rf src
	rm -f random.bin
	rm -f random.bin.gz
	rm -f *.time
