#include<stdio.h>
#include<time.h>
double getMilliseconds( ) { 
   return (1000.0 * clock( ) / CLOCKS_PER_SEC) ;
} 
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
 
// The main program calls fun() and measures time taken by fun()
int main()
{
	double elapsed; 
	elapsed = getMilliseconds(); 
	fun();
	elapsed = getMilliseconds() - elapsed; 
	printf("Elapsed milliseconds = %g", elapsed); 
 
	return 0;

}
