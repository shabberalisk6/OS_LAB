#include <stdio.h>

// Function to check if a page is present in the array
int isPagePresent(int frames[], int pageNumber, int numberOfFrames) {
    for (int i = 0; i < numberOfFrames; i++) {
        if (frames[i] == pageNumber) {
            return 1; // Page is present
        }
    }
    return 0; // Page is not present
}

// Function to perform FIFO page replacement algorithm using arrays
int fifoPageReplacement(int pageSequence[], int numberOfPages, int numberOfFrames) {
    int frames[numberOfFrames];
    int pageFaults = 0;
    int currentIndex = 0;
    for(int i=0;i<numberOfFrames ; i++)
    {
    	frames[i]=-1;
	}

    for (int i = 0; i < numberOfPages; i++) {
        if (!isPagePresent(frames, pageSequence[i], numberOfFrames)) {
            pageFaults++;
            
            frames[currentIndex] = pageSequence[i];
            currentIndex = (currentIndex + 1) % numberOfFrames;

            printf("Page %d inserted into frame: [", pageSequence[i]);
            for (int j = 0; j < numberOfFrames; j++) {
                printf("%d", frames[j]);
                if (j < numberOfFrames - 1) {
                    printf(", ");
                }
            }
            printf("]\n");
        } 
		
		
		else {
            printf("Page %d already in frame: [", pageSequence[i]);
            for (int j = 0; j < numberOfFrames; j++) {
                printf("%d", frames[j]);
                if (j < numberOfFrames - 1) {
                    printf(", ");
                }
            }
            printf("]\n");
        }
    }

    return pageFaults;
}

int main() {
    int numberOfFrames, numberOfPages;

    printf("Enter the number of frames: ");
    scanf("%d", &numberOfFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &numberOfPages);

    int pageSequence[numberOfPages];
    printf("Enter the page sequence (space-separated): ");
    for (int i = 0; i < numberOfPages; i++) {
        scanf("%d", &pageSequence[i]);
    }

    int pageFaults = fifoPageReplacement(pageSequence, numberOfPages, numberOfFrames);

        printf("Number of page faults using FIFO: %d\n", pageFaults);


    return 0;
}

