#include <stdio.h>
#include <stdlib.h>

struct Process {
  int pid;
  int arrivalTime;
  int burstTime;
  int remainingTime;
  int waitingTime;
  int turnaroundTime;
};

void roundRobinScheduling(struct Process processes[], int n, int timeQuantum) {
  int currentTime = 0;
  int completedProcesses = 0;
  int quantumCounter = 0;

  while (completedProcesses < n) {
  for (int i = 0; i < n; i++) {
  if (processes[i].remainingTime > 0) {
  if (processes[i].remainingTime <= timeQuantum) {
  currentTime += processes[i].remainingTime;
  processes[i].remainingTime = 0;
  processes[i].turnaroundTime = currentTime - processes[i].arrivalTime;
  processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
  completedProcesses++;
  } else {
  currentTime += timeQuantum;
  processes[i].remainingTime -= timeQuantum;
  }
  }
  }
  quantumCounter++;
  }
}

int main() {
  int n, timeQuantum;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct Process processes[n];

  for (int i = 0; i < n; i++) {
  printf("Enter arrival time for process %d: ", i + 1);
  scanf("%d", &processes[i].arrivalTime);
  printf("Enter burst time for process %d: ", i + 1);
  scanf("%d", &processes[i].burstTime);
  processes[i].remainingTime = processes[i].burstTime;
  processes[i].pid = i + 1;
  }

  printf("Enter the time quantum: ");
  scanf("%d", &timeQuantum);

  roundRobinScheduling(processes, n, timeQuantum);

  printf("\nGantt Chart:\n");
  for (int i = 0; i < n; i++) {
  printf("| P%d ", processes[i].pid);
  }
  printf("|\n");

  printf("\nProcess\tTurnaround Time\tWaiting Time\n");
  float totalTurnaroundTime = 0;
  float totalWaitingTime = 0;
  for (int i = 0; i < n; i++) {
  printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].turnaroundTime, processes[i].waitingTime);
  totalTurnaroundTime += processes[i].turnaroundTime;
  totalWaitingTime += processes[i].waitingTime;
  }

  float averageTurnaroundTime = totalTurnaroundTime / n;
  float averageWaitingTime = totalWaitingTime / n;

  printf("\nAverage Turnaround Time: %.2f", averageTurnaroundTime);
  printf("\nAverage Waiting Time: %.2f", averageWaitingTime);

  return 0;
}
