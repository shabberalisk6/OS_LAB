#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3
#define NUM_PAGES 10

// Function to initialize the page table
void initializePageTable(int pageTable[], int size) {
    for (int i = 0; i < size; i++) {
        pageTable[i] = -1; // -1 indicates an empty frame
    }
}

// Function to display the contents of the page table
void displayPageTable(int pageTable[], int size) {
    printf("Page Table: ");
    for (int i = 0; i < size; i++) {
        if (pageTable[i] == -1) {
            printf("[ ] ");
        } else {
            printf("[%d] ", pageTable[i]);
        }
    }
    printf("\n");
}

// Function to check if a page is present in the page table
bool isPagePresent(int pageTable[], int size, int page) {
    for (int i = 0; i < size; i++) {
        if (pageTable[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to perform page replacement using FIFO algorithm
void pageReplacementFIFO(int pageTable[], int size, int pages[], int numPages) {
    int front = 0; // Index of the front of the queue

    for (int i = 0; i < numPages; i++) {
        printf("Accessing Page %d\n", pages[i]);
        
        if (!isPagePresent(pageTable, size, pages[i])) {
            // Page fault: Page is not present in the page table
            printf("Page Fault! ");

            if (pageTable[front] != -1) {
                printf("Replacing Page %d \t", pageTable[front]);
            }

            pageTable[front] = pages[i]; // Replace the page at the front of the queue
            front = (front + 1) % size; // Update the front index in a circular manner
        }

        displayPageTable(pageTable, size);
    }
}

int main() {
    int pageTable[NUM_FRAMES];
    int pages[NUM_PAGES] = {0, 1, 2, 3, 2, 4, 5, 3, 4, 6};

    initializePageTable(pageTable, NUM_FRAMES);
    displayPageTable(pageTable, NUM_FRAMES);

    pageReplacementFIFO(pageTable, NUM_FRAMES, pages, NUM_PAGES);

    return 0;
}
