#include <stdio.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};

// Function to perform SJF scheduling
void sjf(struct Process processes[], int n) {
    int time = 0;
    int completed_processes = 0;
    int shortest_index;
    
    while (completed_processes < n) {
        shortest_index = -1;
        
        // Find the process with the shortest remaining time among arrived processes
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (shortest_index == -1 || processes[i].remaining_time < processes[shortest_index].remaining_time) {
                    shortest_index = i;
                }
            }
        }

        if (shortest_index == -1) {
            // No process is ready to execute, find the next arrival time
            int next_arrival = processes[0].arrival_time;
            for (int i = 1; i < n; i++) {
                if (processes[i].arrival_time > time && processes[i].arrival_time < next_arrival) {
                    next_arrival = processes[i].arrival_time;
                }
            }
            time = next_arrival;
        } else {
            // Execute the shortest remaining time process
            time += processes[shortest_index].burst_time;
            processes[shortest_index].remaining_time = 0;
            completed_processes++;

            // Calculate Turnaround Time and Waiting Time
            processes[shortest_index].turnaround_time = time - processes[shortest_index].arrival_time;
            processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;

            printf("Process %d completed at time %d.\n",
                   processes[shortest_index].process_id, time);
        }
    }

    // Calculate total Turnaround Time and total Waiting Time
    float total_turnaround_time = 0;
    float total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    // Print total Turnaround Time and total Waiting Time
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time/n);
    printf("Average Waiting Time: %.2f\n", total_waiting_time/n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time for Process %d: ", processes[i].process_id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", processes[i].process_id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Perform SJF scheduling
    sjf(processes, n);

    return 0;
}
