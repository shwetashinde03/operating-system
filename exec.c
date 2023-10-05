#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int pid=fork();
char *binarypath="/bin/ls";
char*arg1="-lh";
char*arg2="/home";
execl(binarypath,binarypath,arg1,arg2,NULL);
if(pid>0)
{
printf("parent");
}
else if(pid==0)
{
printf("child");
sleep(5);
}
}

