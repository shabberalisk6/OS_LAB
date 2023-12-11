#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[100];
    int n, initialHead;

    printf("Enter no. of requests : ");
    scanf("%d", &n);

    printf("Enter requests in sequence : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial Head position : ");
    scanf("%d", &initialHead);

    int headMovement = 0;
    for(int i = 0; i < n; i++) {
        headMovement += abs(request[i] - initialHead);
        initialHead = request[i];
    }

    printf("*****************************\n");
    printf("Total Head Movements are :  %d\n", headMovement);

    return 0;
}
