#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 65536 // Page size (you can adjust it according to your needs)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <memory_amount>\n", argv[0]);
        return 1;
    }

    long memory_amount = atol(argv[1]);
    long allocated_memory = 0;
    long memory_increment = PAGE_SIZE;

    while (allocated_memory < memory_amount) {
        if (allocated_memory + memory_increment > memory_amount) {
            memory_increment = memory_amount - allocated_memory;
        }

        void *memory_block = malloc(memory_increment);
        if (memory_block == NULL) {
            printf("Failed to allocate additional memory.\n");
            break;
        }

        allocated_memory += memory_increment;
        printf("Allocated memory: %ld bytes\n", allocated_memory);
    }

    printf("Program completed.\n");
    return 0;
}
