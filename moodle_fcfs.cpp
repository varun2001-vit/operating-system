#include <stdio.h>

struct process
{
    int pid;
    int at;  // arrival time
    int bt;  // burst time
    int wt;  // waiting time
    int tat; // turn around time
};

int main()
{
    int n, i, j;
    printf("Enter number of processes:\n");
    scanf("%d", &n); // store the number of processes

    struct process p[n], temp;

    for (i = 0; i < n; i++) // take the arrival times and burst times of the processes
    {
        printf("Process %d:\n", i + 1);
        p[i].pid=i+1;
        printf("Arrival time:\n");
        scanf("%d", &p[i].at);
        printf("Burst time:\n");
        scanf("%d", &p[i].bt);
    }

    for (i = 0; i < n; i++) // sort the array of processes in the order of their arrival
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    float atat = 0, awt = 0;
    int tp = 0;

    for (i = 0; i < n; i++)
    {
        p[i].wt = tp - p[i].at;       // waiting time is time passed - arrival time
        p[i].tat = p[i].wt + p[i].bt; // turn around time is waiting time + burst time
        awt += (float)p[i].wt;        // to add the waiting times of all processes
        atat += (float)p[i].tat;      // to add the turn around times of all the processes
        tp += p[i].bt;                // to keep track of the time passed
    }

    atat = atat / n; // average turn around time
    awt = awt / n;   // average waiting time

    printf("Process\tArrival time\tBurst time\tWaiting time\tTurn around time\n");
    for (i = 0; i < n; i++) // display the calculated waiting times of the processes
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("Average turn around time: %f\n", atat); // display the aerage turn around time
    printf("Average waiting time: %f\n", awt);      // display the average waiting time

    return 0;
}
