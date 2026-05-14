#include<stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, j, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    // Sort processes based on burst time (Bubble Sort)
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(bt[j] > bt[j+1]) {
                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                // Swap process IDs
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // Calculate waiting and turnaround times
    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = tat[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i = 0; i < n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time -- %.2f", wtavg/n);
    printf("\nAverage Turnaround Time -- %.2f\n", tatavg/n);
    return 0;
}
