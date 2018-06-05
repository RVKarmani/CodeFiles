#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>

COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int rec=0;
char nam[50][50];
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
	window(25,50,20,32);
    gotoxy(33,18);
	printf("MENU");
	while(1)
    {
		gotoxy(30,23);
		printf("1.ADD CONTACT");
		gotoxy(30,24);
		printf("2.VIEW CONTACTS");
		gotoxy(30,25);
		printf("3.LINEAR SEARCH");
		gotoxy(30,26);
		printf("4.INTERPOLATION SEARCH");
		gotoxy(30,26);
		printf("5.EXIT");
		printf("\n\nEnter choice: ");
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
				printf("Enter interpolation code");break;
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

