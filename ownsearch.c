#include <stdio.h>
#include <string.h>
#include<time.h>
void main()
{
    int i,j,n,low,high,mid;
	char name[10][8], tname[10][8], temp[8],key[10],ename[10][8],oname[10][8];
    printf("Enter the value of n \n");
    scanf("%d", &n);
    printf("Enter %d names n",n );
    for (i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
        strcpy(tname[i], name[i]);
    }
    for (i = 0; i < n - 1 ; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name[i], name[j]) > 0)
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }
    printf("\n----------------------------------------\n");
    printf("Input Names\tSorted names\n");
    printf("------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%s\n", tname[i], name[i]);
    }
    printf("------------------------------------------\n");
	printf("enter the name to be searched\n");
 	scanf("%s",&key);
	low=0;
 	high=n-1;
 	while(low<=high)
 	{
 		mid=(low+high)/2;
	 	if (strcmp(key,name[mid])==0)
	 	{
	 		printf("key found at the position %d\n",mid+1);
		    exit(0);
	 	}
	 	else if(strcmp(key,name[mid])>0)
	 	{
	 		high=high;
	 		low=mid+1;
	 	}
	 	else
	 	{
		 	low=low;
		 	high=mid-1;
 		}
 	}
 	printf("name not found\n");
 	int e,o=0;
 	for(i=0;i<n;i++)
 	{
 		if(strlen(tname[i])%2==0)
		{
			strcpy(tname[i],ename[e]);e++;
		}		
		else
		{
			strcpy(tname[i],oname[o]);o++;
		}
	}
	printf("\nEven names\n");
	for(i=0;i<e;i++)
	{
		printf(ename[i]);	
	}
	printf("\nOdd names\n");
	for(i=0;i<o;i++)
	{
		printf(oname[i]);
	}
 	
}
