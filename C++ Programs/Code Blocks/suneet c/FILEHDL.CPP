//To Check Structures, Link Lists, File Handling and fwrite/fread functions
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<ctype.h>
#define FILENAME "C:\\Noname.Dat"
struct test
{
	int roll;
	char name[20];
	int mk;
	struct test*link;
} *first=(struct test *)malloc(sizeof(test));
void main()
{
	void prin(struct test*),fre(struct test*);
	int save(struct test*,FILE*);
	struct test*read(FILE*),*tree;
	char ct;
	clrscr();
	tree=first;
	do
	{
		printf("Enter Roll no : ");
		scanf("%d",&tree->roll);
		printf("Enter Name : ");
		fflush(stdin);
		gets(tree->name);
		printf("Enter Marks : ");
		fflush(stdin);
		scanf("%d",&tree->mk);
		printf("Any More (y/n)? ");
		ct=tolower(getche());
		if(ct=='y')
		{
			tree->link=(struct test *)malloc(sizeof(test));
			tree=tree->link;
			printf("\n");
		}
		else
			tree->link=NULL;
	}while(ct=='y');
	clrscr();
	printf("\nBefore Saving to the File\n");
	prin(first);
	FILE *tst;
	if(!(tst=fopen(FILENAME,"w+")))
		return;
	save(first,tst);
	fre(first);
	fflush(tst);
	fseek(tst,0,SEEK_SET);
	first=read(tst);
	fclose(tst);
	printf("\nAfter Reading from the File\n");
	prin(first);
	getch();
}
/*Function to print a Link List with first value struct test*tree */
void prin(struct test* tree)
{
	printf("\nR.No\tName\t\t\tMarks\n----\t----\t\t\t-----\n");
	while(tree)
	{
		printf("%d\t%-20s\t%-3d\n",tree->roll,tree->name,tree->mk);
		tree=tree->link;
	}
}
/*Function to save a Link List with first value struct test*tree to a
file FILE*tst. Function returns the number of items saved*/
int save(struct test*tree,FILE*tst)
{
	int num=0;
	while(tree)
	{
		fwrite(tree,sizeof(test),1,tst);
		tree=tree->link;
		num++;
	}
	return num;
}
/*Function to read values from a file given by the file pointer FILE*tst
and return a link list with first value*/
struct test*read(FILE*tst)
{
	struct test temp,*first=(struct test*)malloc(sizeof(struct test));
	fread(first,sizeof(test),1,tst);
	struct test*tree=first;
	tree->link=NULL;
	for(;;)
		if(fread(&temp,sizeof(test),1,tst))
		{
			tree->link=(struct test*)malloc(sizeof(struct test));
			tree=tree->link;
			*tree=temp;
			tree->link=NULL;
		}
		else
			return first;
}
/*Function to free the memory held by a link list struct test*first */
void fre(struct test*first)
{
	struct test*tree=first,*prev;
	while(tree->link)
	{
		prev=tree;
		tree=tree->link;
	}
	if(tree==first)
	{
		free(first);
		return;
	}
	free(tree);
	prev->link=NULL;
	fre(first);
}