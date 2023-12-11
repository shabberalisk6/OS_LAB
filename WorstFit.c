#include <stdio.h>

#define MAX_BLOCKS 50

// Structure to represent a memory block
struct Block {
    int id;
    int size;

};

// Function to find the worst fit for a given block size
int worstFit(struct Block blocks[], int m, int size) {
    int worstIdx = -1;
    int maxSize = -1;

    for (int i = 0; i < m; i++) {
        if ( blocks[i].size >= size) {
            if (blocks[i].size > maxSize) {
                maxSize = blocks[i].size;
                worstIdx = i;
            }
        }
    }

    return worstIdx;
}

// Function to allocate memory using Worst Fit
void allocateMemory(struct Block blocks[], int m, int processId, int size) {
    int blockIndex = worstFit(blocks, m, size);

    if (blockIndex != -1) {
        blocks[blockIndex].size-=size;
         printf("\nProcess %d allocated to Block %d .. REMAINING BLOCKSIZE : %d \n", processId, blocks[blockIndex].id , blocks[blockIndex].size);
 
         
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
