#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3 // Maximum number of frames in memory

// Function to find the index of the page in the frames
int findPage(int page, int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return i;
        }
    }
    return -1; // Page not found in frames
}

// Function to implement LRU page replacement
void lruPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];
    int counter[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Initialize frames to -1 (indicating empty)
        counter[i] = 0; // Initialize counter to 0
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        int pageIdx = findPage(page, frames, MAX_FRAMES);

        if (pageIdx == -1) {
            // Page fault: Page is not present in frames
            int replaceIdx = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (counter[j] < counter[replaceIdx]) {
                    replaceIdx = j;
                }
            }

            frames[replaceIdx] = page;
            counter[replaceIdx] = i + 1; // Update counter with the current time
            pageFaults++;
        } else {
            // Page is already present in frames
            counter[pageIdx] = i + 1; // Update counter with the current time
        }

        // Print the current state of frames
        printf("Frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    // Example sequence of page requests
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(pages) / sizeof(pages[0]);

    lruPageReplacement(pages, n);

    return 0;
}
