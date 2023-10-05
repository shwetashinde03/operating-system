#include<stdio.h>
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3
int canAllocate(int need[MAX_PROCESSES][MAX_RESOURCES],
int available[MAX_RESOURCES],int process,int request[MAX_RESOURCES]){
for(int i=0;i<MAX_RESOURCES;i++){
if(request[i]>need[process][i] || request[i]>available[i]){
return 0;
}
}
return 1;
}
void allocateResources(int allocated[MAX_PROCESSES][MAX_RESOURCES],int available[MAX_RESOURCES],int process,int request[MAX_RESOURCES]){
for(int i=0;i<MAX_RESOURCES;i++){
allocated[process][i]+=request[i];
available[i]-=request[i];
}
}
void releaseResources(int allocate[MAX_PROCESSES][MAX_RESOURCES],int available[MAX_RESOURCES],int process,int release[MAX_RESOURCES]){
for(int i=0;i<MAX_RESOURCES;i++){
allocate[process][i]-=release[i];
available[i]+=release[i];
}
}
int main(){
int allocate[MAX_PROCESSES][MAX_RESOURCES]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int max[MAX_PROCESSES][MAX_RESOURCES]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int available[MAX_RESOURCES]={3,3,2};
int need[MAX_PROCESSES][MAX_RESOURCES];
for(int i=0;i<MAX_PROCESSES;i++){
for(int j=0;j<MAX_RESOURCES;j++){
need[i][j]=max[i][j]-allocate[i][j];
}
}
int request[MAX_RESOURCES]={0,0,0};
int process;
printf("Enter resources request for process %d:",process);
for(int i=0;i<MAX_RESOURCES;i++){
scanf("%d",&request[i]);
}
if(canAllocate(need,available,process,request)){
allocateResources(allocate,available,process,request);
printf("Resource allocated successfully,\n");
}
else{
printf("Resource allocation failed.process must wait to avoid deadlock.\n");
}
return 0;
}

