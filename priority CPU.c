#include<stdio.h>

int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;


    printf("Masukkan jumlah proses --- ");
    scanf("%d", &n);

    // Input proses
    for(i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Masukkan Burst Time & Prioritas Proses %d --- ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sorting berdasarkan prioritas (priority scheduling)
    for(i = 0; i < n; i++)
    {
        for(k = i + 1; k < n; k++)
        {
            if(pri[i] > pri[k])
            {
                // Tukar proses
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Tukar burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Tukar prioritas
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    // Hitung waiting time dan turnaround time
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    // Tampilkan hasil
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");

    for(i = 0; i < n; i++)
    {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\nRata-rata Waiting Time is --- %f", wtavg/n);
    printf("\nRata-rata Turnaround Time is --- %f", tatavg/n);

    return 0;
}
