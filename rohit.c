#include<stdio.h>
#include<string.h>
#include<time.h>
int rec=0;
char nam[50][50],oname[50][50],ename[50][50];
char pho[50][50];
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
		printf("\n1.ADD CONTACT\n2.VIEW CONTACTS\n3.LINEAR SEARCH\n4.INTERPOLATION SEARCH\n5.EXIT\n");
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
				t_lsearch=((double)(end-start))*1000/CLOCKS_PER_SEC;
				printf("\nTime taken to execute linear search is %f",t_lsearch);
				break;
			case 4:
				osearch();break;
			case 5:
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
void osearch()
{
	int i,l;
	int e,o=0;
	char osearch;
	printf("Enter name to be search");
	scanf("%s",&osearch);
	l=strlen(osearch);
	for(i=0;i<rec;i++)
	{
		if(strlen(nam[i])%2==0)
		{
			strcpy(nam[i],ename[e]);e++;
		}
		else
		{
			strcpy(nam[i],oname[o]);o++;
		}
	}
	if(l%2==0)
	{
		for(i=0;i<e+1;i++)
		{
			if(strcmp(osearch,ename[i])==0){printf("Contact Found");}
			else{printf("Contact not found");}
			
			
		}
	}
	else
	{
		for(i=0;i<o+1;i++)
		{
			if(strcmp(osearch,oname[i])==0){printf("Contact found");}
			else{printf("Contact not found");}
			
		}
		
	}
	
	
	
}

