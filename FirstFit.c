#include <stdio.h>

#define MAX_BLOCKS 50

// Structure to represent a memory block
struct Block {
    int id;
    int size;

};

// Function to find the first fit for a given block size
int firstFit(struct Block blocks[], int m, int size) {
    for (int i = 0; i < m; i++) {
        if (blocks[i].size >= size) {
            return i;
        }
    }
    return -1; // No suitable block found
}

// Function to allocate memory using First Fit
void allocateMemory(struct Block blocks[], int m, int processId, int size) {
    int blockIndex = firstFit(blocks, m, size);

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
