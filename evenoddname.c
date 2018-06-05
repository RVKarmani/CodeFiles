#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	int e=0;
	int o=0;
	char name[100][100],ename[50][100],oname[50][100];
	for(i=0;i<5;i++)
	{
		printf("Enter name: ");
		scanf("%s",name[i]);
		if(strlen(name[i])%2==0)
		{
			strcpy(name[i],ename[e]);e++;
		}
		else
		{
			strcpy(name[i],oname[o]);o++;
		}
	}
	printf("Original names are\t");
	for(i=0;i<5;i++)
	{
		printf("%s",name[i]);
	}
	printf("Names in the even array are\t");
	for(i=0;i<e;i++)
	{
		printf("%s",ename[i]);
	}
	printf("Odd array if names are ");
	for(i=0;i<o;i++)
	{
		printf("%s",oname[i]);
	}
	return 0;
}
