#include <stdio.h>

struct Process {
    int pid;         // Process ID
    int arrival;     // Arrival Time
    int burst;       // Burst Time (Execution Time)
    int wait;        // Waiting Time
    int start;       // Start Time
    int finish;      // Finish Time
    int turnaround;  // Turnaround Time
    int remaining_burst; // Remaining Burst Time (for SJF)
};

void sortByArrivalTime(struct Process p[], int n) {
    // Sorting processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                const struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void sortByBurstTime(struct Process p[], int n, int currentTime) {
    // Sorting processes by burst time (ascending order) for SJF
    // Only consider processes that have arrived before the current time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (p[j].arrival <= currentTime && p[j].remaining_burst > p[j + 1].remaining_burst) {
                const struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculateTime(struct Process p[], int n) {
    int currentTime = 0;
    int completed = 0;

    // Initialize the remaining burst time to the original burst time
    for (int i = 0; i < n; i++) {
        p[i].remaining_burst = p[i].burst;
    }

    while (completed < n) {
        // Sort by burst time, but only consider processes that have arrived by currentTime
        sortByBurstTime(p, n, currentTime);

        int selectedProcess = -1;
        // Find the first process that has arrived and has a remaining burst time
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && p[i].remaining_burst > 0) {
                selectedProcess = i;
                break;
            }
        }

        if (selectedProcess == -1) {
            // No process is ready, increment time and continue
            currentTime++;
            continue;
        }

        // Execute the selected process
        p[selectedProcess].start = currentTime;
        p[selectedProcess].finish = currentTime + p[selectedProcess].remaining_burst;
        p[selectedProcess].turnaround = p[selectedProcess].finish - p[selectedProcess].arrival;
        p[selectedProcess].wait = p[selectedProcess].turnaround - p[selectedProcess].burst;

        // Update the current time and mark the process as completed
        currentTime = p[selectedProcess].finish;
        p[selectedProcess].remaining_burst = 0;  // Process has finished execution
        completed++;
    }
}

void printGanttChart(struct Process p[], int n) {
    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf(" P%d", i + 1);
        if (i != n - 1) {
            printf("|");
        }
    }
    printf("\n");

    printf("%d", p[0].start);
    for (int i = 0; i < n; i++) {
        printf("    %d", p[i].finish);
    }
    printf("\n");
}

void printTable(struct Process p[], int n) {
    printf("\nProcess\tArrival\tBurst\tStart\tFinish\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].start, p[i].finish, p[i].turnaround, p[i].wait);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].pid = i + 1;
    }

    sortByArrivalTime(p, n);
    calculateTime(p, n);
    printGanttChart(p, n);
    printTable(p, n);

    return 0;
}
