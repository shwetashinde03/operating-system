#include<stdio.h>
#include<time.h>
int main()
{
int i,rand;
double total_time;
clock_t start,end;
start=clock();
//srand(time(NULL));
for(i=0;i<25000;i++){
printf("random_number=%d\n",i+1);
}
end=clock();
total_time=((double)(end-start))/CLOCK_TAI;
printf("\nTime taken to print 25000 random number is:%f",total_time);
return 0;
}

