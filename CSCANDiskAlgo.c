#include <stdio.h>
#include <stdlib.h>

void find(int request[],int n , int head, int direction);

int main() {
    int n, initialHead;
    printf("Enter no. of requests : ");
    scanf("%d", &n);

    int request[n];
    printf("Enter requests in sequence : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial Head position : ");
    scanf("%d", &initialHead);

    int cylinder_start, cylinder_end;
    printf("Enter cylinder Starting and Ending position respectively : ");
    scanf("%d %d", &cylinder_start, &cylinder_end);

    // Sorting the requests
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (request[i] > request[j]) {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }
    n=n+2;
    int request_dup[n ];
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            request_dup[i] = cylinder_start;
        } else if (i == n - 1) {
            request_dup[i] = cylinder_end;
        } else {
            request_dup[i] = request[i - 1];
        }
    }

    printf("Enter the direction (0->left , 1->right) : ");
    int direction;
    scanf("%d", &direction);

    find(request_dup,n, initialHead, direction);

    return 0;
}

void find(int request[], int n, int head, int direction) {
    int TotalHeadMovement = 0;
    int index;

    for (index = 0; index < n; index++) {
        if (request[index] > head)
            break;
    }
    printf("%d\n", index);
   // in CSACn in both directions the answer is same 
    if (direction == 0 || direction==1) {
        TotalHeadMovement = 2 * request[n-1] - abs(head - request[index - 1]);
        printf("Total Head Movement In left direction : %d\n", TotalHeadMovement);
    } 
}
