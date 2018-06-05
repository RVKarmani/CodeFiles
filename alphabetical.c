#include <stdio.h>
#include <string.h>
 
void main()
{
    int i,j,n,low,high,mid;
	char name[10][8], tname[10][8], temp[8],key[10];
   
    for (i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
        strcpy(name[i], tname[i]);
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
}
   
