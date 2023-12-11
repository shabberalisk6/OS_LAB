#include <stdio.h>

#define MAX_BLOCKS 50
#define INT_MAX 999

// Structure to represent a memory block
struct Block {
    int id;
    int size;

};

// Function to find the best fit for a given block size
int bestFit(struct Block blocks[], int m, int size) {
    int bestIdx = -1;
    int minSize = INT_MAX;

    // Iterate through the available blocks
    for (int i = 0; i < m; i++) {
        // Check if the block is unallocated and has sufficient size
        if ( blocks[i].size >= size) {
            // Check if it's the best fit so far
            if (blocks[i].size < minSize) {
                minSize = blocks[i].size;
                bestIdx = i;
            }
        }
    }

    return bestIdx;
}

// Function to allocate memory using Best Fit
void allocateMemory(struct Block blocks[], int m, int processId, int size) {
    int bestIdx = bestFit(blocks, m, size);

    // Check if a suitable block is found
    if (bestIdx != -1) {
        blocks[bestIdx].size-=size;
        printf("\nProcess %d allocated to Block %d .. REMAINING BLOCKSIZE : %d \n", processId, blocks[bestIdx].id , blocks[bestIdx].size);
    } else {
        printf("Cannot allocate memory for Process %d\n", processId);
    }
}



int main() {
    struct Block blocks[MAX_BLOCKS];
    int m; // Number of memory blocks

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    // Input the details of each memory block
    for (int i = 0; i < m; i++) {
        printf("Enter size of Block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].id = i + 1;
    }

    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the size of each process and allocate memory
    for (int i = 0; i < n; i++) {
        int size;
        printf("Enter size of Process %d: ", i + 1);
        scanf("%d", &size);

        allocateMemory(blocks, m, i + 1, size);

    }

    return 0;
}
