#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    int id, arrival, burst, priority;
    int remaining, start, finish, waiting, turnaround;
};

// Function to print a Gantt Chart visually
void printGantt(int order[], int start[], int end[], int count) {
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < count; i++) printf("------");
    printf("\n|");
    for (int i = 0; i < count; i++) printf(" P%d |", order[i]);
    printf("\n ");
    for (int i = 0; i < count; i++) printf("------");
    printf("\n0");
    for (int i = 0; i < count; i++) printf("     %d", end[i]);
    printf("\n");
}

// Function to print result table
void printTable(struct Process p[], int n, const char *algo) {
    printf("\n--- %s Results ---\n", algo);
    printf("PID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    float totalW = 0, totalT = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].priority, p[i].waiting, p[i].turnaround);
        totalW += p[i].waiting;
        totalT += p[i].turnaround;
    }
    printf("Average Waiting Time = %.2f\n", totalW / n);
    printf("Average Turnaround Time = %.2f\n", totalT / n);
}

// FCFS Scheduling
void FCFS(struct Process p[], int n) {
    printf("\n================ FCFS Scheduling ================\n");
    int time = 0, order[50], start[50], end[50], count = 0;

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[j].arrival < p[i].arrival) {
                struct Process temp = p[i]; p[i] = p[j]; p[j] = temp;
            }

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival) time = p[i].arrival;
        p[i].start = time;
        time += p[i].burst;
        p[i].finish = time;
        p[i].turnaround = p[i].finish - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        order[count] = p[i].id;
        start[count] = p[i].start;
        end[count] = p[i].finish;
        count++;
    }
    printGantt(order, start, end, count);
    printTable(p, n, "FCFS");
}

// SJF Scheduling
void SJF(struct Process p[], int n) {
    printf("\n================ SJF Scheduling ================\n");
    int time = 0, completed = 0, done[10] = {0};
    int order[50], start[50], end[50], count = 0;

    while (completed < n) {
        int idx = -1, minBurst = 9999;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                idx = i;
            }
        }
        if (idx == -1) { time++; continue; }

        p[idx].start = time;
        time += p[idx].burst;
        p[idx].finish = time;
        p[idx].turnaround = p[idx].finish - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;

        done[idx] = 1;
        order[count] = p[idx].id;
        start[count] = p[idx].start;
        end[count] = p[idx].finish;
        count++;
        completed++;
    }
    printGantt(order, start, end, count);
    printTable(p, n, "SJF");
}

// Round Robin Scheduling
void RoundRobin(struct Process p[], int n, int quantum) {
    printf("\n================ Round Robin (q=%d) ================\n", quantum);
    int time = 0, completed = 0;
    int order[100], start[100], end[100], count = 0;

    for (int i = 0; i < n; i++) {
        p[i].remaining = p[i].burst;
        p[i].start = -1;
    }

    while (completed < n) {
        int allIdle = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                allIdle = 0;
                if (p[i].start == -1) p[i].start = time;
                int exec = (p[i].remaining > quantum) ? quantum : p[i].remaining;
                start[count] = time;
                time += exec;
                end[count] = time;
                order[count] = p[i].id;
                count++;
                p[i].remaining -= exec;
                if (p[i].remaining == 0) {
                    p[i].finish = time;
                    p[i].turnaround = p[i].finish - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    completed++;
                }
            }
        }
        if (allIdle) time++;
    }
    printGantt(order, start, end, count);
    printTable(p, n, "Round Robin");
}

// Priority Scheduling
void PriorityScheduling(struct Process p[], int n) {
    printf("\n================ Priority Scheduling ================\n");
    int order[50], start[50], end[50], count = 0;
    int time = 0;

    // Sort by priority descending
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[j].priority > p[i].priority) {
                struct Process temp = p[i]; p[i] = p[j]; p[j] = temp;
            }

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival) time = p[i].arrival;
        p[i].start = time;
        time += p[i].burst;
        p[i].finish = time;
        p[i].turnaround = p[i].finish - p[i].arrival;
        p[i].waiting = p[i].turnaroun
