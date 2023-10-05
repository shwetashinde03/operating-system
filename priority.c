#include<stdio.h>
#include<stdlib.h>

struct Process {
  int pid;
  int arrival_time;
  int burst_time;
  int priority;
  int remaining_time;
  int waiting_time;
  int turnaround_time;
};

void sort_by_priority(struct Process *processes, int n) {
  for (int i = 0; i < n - 1; i++) {
  for (int j = 0; j < n - i - 1; j++) {
  if (processes[j].priority > processes[j + 1].priority) {
  struct Process temp = processes[j];
  processes[j] = processes[j + 1];
  processes[j + 1] = temp;
  }
  }
  }
}

void simulate_preemptive_priority(struct Process *processes, int n) {
  int current_time = 0;
  int completed_processes = 0;

  while (completed_processes < n) {
  int highest_priority = -1;
  int highest_priority_index = -1;

  for (int i = 0; i < n; i++) {
  if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
  if (highest_priority == -1 || processes[i].priority < highest_priority) {
  highest_priority = processes[i].priority;
  highest_priority_index = i;
  }
  }
  }

  if (highest_priority_index == -1) {
  current_time++;
  continue;
  }

  processes[highest_priority_index].remaining_time--;
  current_time++;

  if (processes[highest_priority_index].remaining_time == 0) {
  completed_processes++;
  processes[highest_priority_index].turnaround_time = current_time - processes[highest_priority_index].arrival_time;
  processes[highest_priority_index].waiting_time = processes[highest_priority_index].turnaround_time - processes[highest_priority_index].burst_time;
  }
  }
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct Process *processes = (struct Process*) malloc(n * sizeof(struct Process));

  for (int i = 0; i < n; i++) {
  printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
  scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
  processes[i].pid = i + 1;
  processes[i].remaining_time = processes[i].burst_time;
  }

  sort_by_priority(processes, n);
  simulate_preemptive_priority(processes, n);

  printf("\nGantt Chart:\n");
  for (int i = 0; i < n; i++) {
  printf("P%d ", processes[i].pid);
  }
  printf("\n");

  float total_waiting_time = 0;
  float total_turnaround_time = 0;

  printf("\nProcess\tTurnaround Time\tWaiting Time\n");
  for (int i = 0; i < n; i++) {
  printf("P%d\t%d\t\t%d\n", processes[i].pid, processes[i].turnaround_time, processes[i].waiting_time);
  total_waiting_time += processes[i].waiting_time;
  total_turnaround_time += processes[i].turnaround_time;
  }

  float average_waiting_time = total_waiting_time / n;
  float average_turnaround_time = total_turnaround_time / n;

  printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
  printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

  free(processes);

  return 0;
}
