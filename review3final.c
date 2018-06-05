#include<stdio.h>
#include<string.h>
#include<time.h>
int rec=0;
int i,j,n,low,high,mid;
char nam[50][50],temp[50],key[50];
char pho[50][50],tnam[50][50];
struct dir
{
	char name[50],tel[50];
};
struct dir con[50];
void add();
void view();
void lsearch();
int main()
{
	int ch;
	double t_lsearch;
	clock_t start,end;
	printf("MENU");
	while(1)
    {
		printf("\n1.ADD CONTACT\n2.VIEW CONTACTS\n3.LINEAR SEARCH\n4.BINARY  SEARCH\n5.EXIT\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
	{

			case 1:
				add();break;
			case 2:
				view();break;
			case 3:
				start=clock();
				lsearch();
				end=clock();
				t_lsearch=((double)(end-start))/CLOCKS_PER_SEC;
				printf("\nTime taken to execute linear search is %f",t_lsearch);
				break;
			case 4:
				bsearch();break;
		
			default:
				printf("Wrong choice selected");break;
		}

	}

}
void add()
{

	printf("Enter name: ")	;
	scanf("%s",&con[rec].name);
	strcpy(nam[rec],con[rec].name);
	strcpy(nam[rec], tnam[rec]);
	printf("Enter number");
	scanf("%s",&con[rec].tel);
	strcpy(pho[rec],con[rec].tel);
	rec++;

}
void view()
{
	int i;
	for(i=0;i<rec;i++)
	{
		printf("\n==============");
		printf("\nDirectory#%d",i+1);
		printf("\nName:%s" ,con[i].name);
		printf("\nNumber: %s",con[i].tel);
	}
	printf("\n==============");
}
void lsearch()
{

	int i,choice;
	char lsearch[50];
	printf("1=Search by name\n2=Search by number");
	scanf("%d",&choice);
	if(choice==1)
	{
	printf("\nEnter name to search:");
	scanf("%s",&lsearch);
	for(i=0;i<rec;i++)
	{
		if(strcmp(nam[i],lsearch)==0)
		{
			   printf("\nContact found");
			   return	;
  }}
		printf("\nContact Not Found");
	}
	else if(choice==2)
	{
		printf("\nEnter number to search:");
		scanf("%s",&lsearch);
	for(i=0;i<rec;i++)
	{
		if(strcmp(pho[i],lsearch)==0)
		{
			   printf("\nContact found");
			   return	;
  }}
		printf("\nContact Not Found");
	}
	else
	printf("Wrong choice");
}
void bsearch()
{
	for (i = 0; i < rec+1; i++)
    {
        strcpy(nam[i], tnam[i]);
    }
    for (i = 0; i < rec ; i++)
    {
        for (j = i + 1; j < rec; j++)
        {
            if (strcmp(tnam[i], tnam[j]) > 0)
            {
                strcpy(temp, tnam[i]);
                strcpy(tnam[i], tnam[j]);
                strcpy(tnam[j], temp);
            }
        }
    }
    printf("\n----------------------------------------\n");
    printf("Input Names\tSorted names\n");
    printf("------------------------------------------\n");
    for (i = 0; i < rec+1; i++)
    {
        printf("%s\t\t%s\n", nam[i], tnam[i]);
    }
    printf("------------------------------------------\n");
	printf("enter the name to be searched\n");
 	scanf("%s",&key);
	low=0;
 	high=rec;
 	while(low<=high)
 	{
 		mid=(low+high)/2;
	 	if (strcmp(key,tnam[mid])==0)
	 	{
	 		printf("key found at the position %d\n",mid+1);
		    exit(0);
	 	}
	 	else if(strcmp(key,tnam[mid])>0)
	 	{
	 		high=high;
	 		low=mid+1;
	 	}
	 	else
	 	{
		 	low=low;
		 	high=mid-1;
		 	printf("name not found\n");	
 		}
 	}
 	
	
}
