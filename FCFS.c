#include<stdio.h>

void insertionSort(char pid[][10], int AT[], int BT[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (AT[j] < AT[j - 1]) {
                // Swap Arrival Time
                int temp = AT[j];
                AT[j] = AT[j - 1];
                AT[j - 1] = temp;

                // Swap Burst Time
                temp = BT[j];
                BT[j] = BT[j - 1];
                BT[j - 1] = temp;

                // Swap Process ID
                char tempPid[10];
                strcpy(tempPid, pid[j]);
                strcpy(pid[j], pid[j - 1]);
                strcpy(pid[j - 1], tempPid);
            } else {
                break;
            }
        }
    }
}

int main() {
    printf("Enter no. of processes : ");
    int n;
    scanf("%d", &n);
    char pid[n][10];
    int AT[n], BT[n], CT[n], TAT[n], WT[n], RT[n];

    printf("Enter the process id , Arrival time , Burst time in sequential order : \n");
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d", pid[i], &AT[i], &BT[i]);
    }

    // Using stable sorting (considering arrival time)
    insertionSort(pid, AT, BT, n);

    // Displaying
    printf("-----------------------------\n");
    printf("*********DISPLAYING**********\n");
    printf("-----------------------------\n");
    printf("PID  AT  BT\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", pid[i], AT[i], BT[i]);
    }

    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            CT[i] = AT[i] + BT[i];
            continue;
        }
        if (CT[i - 1] > AT[i]) {
            CT[i] = BT[i] + CT[i - 1];
        } else {
            CT[i] = BT[i] + AT[i];
        }
    }

    double AvgWaitingTime = 0;
    double AvgTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        RT[i] = WT[i];
        AvgTurnAroundTime += TAT[i];
        AvgWaitingTime += WT[i];
    }
    printf("AVERAGE TURN AROUND TIME IS : %.2f\n", AvgTurnAroundTime / n);
    printf("AVERAGE WAITING TIME IS : %.2f\n", AvgWaitingTime / n);

    return 0;
}
