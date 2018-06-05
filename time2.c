#include<stdio.h>
#include<sys/time.h>
void fun()
{
    printf("fun() starts \n");
    printf("Press enter to stop fun \n");
    while(1)
    {
        if (getchar())
            break;
    }
    printf("fun() ends \n");
}
struct timeval start, end;
	gettimeofday(&start, NULL);
	fun();
	gettimeofday(&end, NULL);
	delta = ((end.tv_sec  - start.tv_sec) * 1000000u +	end.tv_usec - start.tv_usec) / 1.e6;
	printf("Time is : %f\n",delta);
intmain()
{
	return 0;
	
	
}
