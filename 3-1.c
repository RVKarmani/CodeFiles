#include<stdio.h>
#include<string.h>
#include<time.h>
int rec=0,erec=0,orec=0;
char nam[50][50],snam[50][50],temp[50];
char pho[50][50],spho[50][50],ename[50][50],oname[50][50];
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
	double t_lsearch,t_bsearch,t_osearch;
	clock_t start,end;
	printf("MENU");
	while(1)
    {
		printf("\n1.ADD CONTACT\n2.VIEW CONTACTS\n3.LINEAR SEARCH\n4.BINARY SEARCH\n5.OSEARCH\n6.EXIT\n");
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
					start=clock();
					bsearch();
					end=clock();
					t_bsearch=((double)(end-start))/CLOCKS_PER_SEC;
					printf("\nTime taken to execute binary search is %f",t_bsearch);
					break;
			case 5:
				start=clock();
				osearch();
				end=clock();
				t_osearch=((double)(end-start))/CLOCKS_PER_SEC;
				printf("\nTime taken to execute own search is %f",t_osearch);
				break;
			case 6:
				exit(0);break;
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
	strcpy(snam[rec],nam[rec]);
	printf("Enter number");
	scanf("%s",&con[rec].tel);
	strcpy(pho[rec],con[rec].tel);
	strcpy(spho[rec],con[rec].tel);
	if(strlen(nam[rec])%2==0)
	strcpy(ename[erec++],nam[rec]);
	else if(strlen(nam[rec])%2==1)
	strcpy(oname[orec++],nam[rec]);
	rec++;
}
void view()
{
	int i;
	for(i=0;i<rec;i++)
	{
		printf("\n------------------");
		printf("\nDirectory#%d",i+1);
		printf("\nName:%s" ,con[i].name);
		printf("\nNumber: %s",con[i].tel);
	}
	printf("\n-----------------");
}
void lsearch()
{

	int i,choice;
	char lsearch[50];
	printf("1=Search by name\n2=Search by number\nEnter choice: ");
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
	char temp[50];
	int i,j,first,last,middle;
	for (i = 0; i < rec-1 ; i++)
    {
        for (j =0; j < rec-i-1; j++)
        {
            if (strcmp(snam[j], snam[j+1]) > 0)
            {
                strcpy(temp, snam[j]);
                strcpy(snam[j], snam[j+1]);
                strcpy(snam[j+1], temp);
                 strcpy(temp, spho[j]);
                strcpy(spho[j], spho[j+1]);
                strcpy(spho[j+1], temp);
            }
        }
    }
    printf("\n----------------------------------------\n");
    printf("Input Names\tSorted names\n");
    printf("------------------------------------------\n");
    for (i = 0; i < rec; i++)
    {
        printf("%s\t\t%s\n", nam[i], snam[i]);
    }
    printf("------------------------------------------\n");
    printf("Enter  a name ");
    scanf("%s",&temp);
     first = 0;
   last = rec - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (strcmp(snam[middle],temp) <0)
         first = middle + 1;    
      else if (strcmp(snam[middle],temp) == 0) {
         printf("Phone number is %s",spho[middle] );
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found\n");
}

void osearch()
{
	int i;
	int eflag =0;
	int oflag=0;
	char names[50];
	printf("Enter the name to be searched: ");
	scanf("%s",&names);
	if(strlen(names)%2==0)
	{
		for(i=0;i<erec;i++)
		{
			if(strcmp(names,ename[i])==0)
			{
				eflag=1;
			}
		}
	}
	else
	{
		for(i=0;i<orec;i++)
		{
			if(strcmp(names,oname[i])==0){oflag=1;}
		}
	}
	if(eflag==1||oflag==1){printf("Contact found");}
	else{printf("Contact not found");}
}
	

