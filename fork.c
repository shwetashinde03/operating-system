#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
pid_t p;
printf("\n before fork\n");
p=fork();
if(p==0)//child
{
printf("\nHello world");
printf("\n I am child having id %d\n",getpid());
printf("\n My parent's id is %d\n",getpid());
}
else
{
printf("\nHi");
printf("\nMy child's id is %d\n",p);
printf("\n I am parent having id%d\n",getpid());
}
}

