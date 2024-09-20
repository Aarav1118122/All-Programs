//To Check Binary Self Referntial Structures, and Structure Sorting.
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
	struct test*link1;
	struct test*link2;
};
void main()
{
	int creat(char*),num,cas;
	void srt(struct test*,struct test*,char),prin(struct test*);
	char sort='\0';
	struct test*read(FILE*),*first,*curr;
	clrscr();
	num=creat(FILENAME);
	clrscr();
	while(!sort)
	{
		printf("\nSort By (N)ame/ (R)oll number/ (M)arks ? ");
		sort=tolower(getche());
		if(!(sort=='n'||sort=='r'||sort=='m'))
		{
			sort='\0';
			clrscr();
		}
	}
	printf("\n\nBefore Sorting\n--------------\nR.No\tName\t\t\tMarks\n----\t----\t\t\t-----\n");
	FILE *tst;
	if(!(tst=fopen(FILENAME,"r")))
	{
		printf("Error Opening File : File does not exist?");
		return;
	}
	if(!(first=read(tst)))
	{
		printf("Error Opening File : File has no Records?");
		fclose(tst);
		return;
	}
	else
		printf("%d\t%-20s\t%d\n",first->roll,first->name,first->mk);
	while(curr=read(tst))
	{
		printf("%d\t%-20s\t%d\n",curr->roll,curr->name,curr->mk);
		srt(first,curr,sort);
	}
	fclose(tst);
	printf("\n\nAfter Sorting by %s\n---------------------%c\nR.No\tName\t\t\tMarks\n----\t----\t\t\t-----\n",sort=='r'?"R.No":sort=='m'?"Marks":"Name ",sort=='m'?'-':' ');
	prin(first);
	getch();
}
/*Function to create a File given by argument char*filename */
int creat(char*filename)
{
	int num=0,cont='y',marks,roll;
	FILE*tst=fopen(filename,"w");
	if(!tst)
		return -1;
	char *name=(char*)malloc(20);
	while(cont=='y')
	{
		num++;
		printf("\nRoll No : ");
		scanf("%d",&roll);
		printf("\Name : ");
		fflush(stdin);
		gets(name);
		printf("Marks : ");
		scanf("%d",&marks);
		printf("Any More (y/n)?");
		cont=tolower(getche());
		fprintf(tst,"%d,%s,%d\n",roll,name,marks);
	}
	fclose(tst);
	return num;
}
/*Function to read a filestream tst and return a pointer to struct test*
using the values read from the stream. Return NULL if EOF*/
struct test*read(FILE*tst)
{
	struct test*fst=(struct test*)malloc(sizeof(struct test));
	char ct;
	int i=0;
	fst->mk=fst->roll=0;
	fst->link1=fst->link2=NULL;
	struct
	{
		unsigned int is_name   : 1;
		unsigned int is_marks  : 1;
		unsigned int is_finish : 1;
	} flags;
	flags.is_name=0;
	flags.is_marks=0;
	flags.is_finish=0;
	while((ct=fgetc(tst))!=EOF)
		switch(ct)
		{
			case',':
				if(flags.is_name)
				{
					fst->name[i]='\0';
					flags.is_marks=1;
				}
				else
					flags.is_name=1;
				break;
			case'\n':
				return fst;
			default:
				if(flags.is_marks)
					fst->mk=fst->mk*10+ct-'0';
				else if(flags.is_name)
					if(i<19)
						fst->name[i++]=ct;
					else
						fst->name[i]='\0';
				else
					fst->roll=fst->roll*10+ct-'0';
		}
	return NULL;
}
/* Function to sort a Binary Structure*/
void srt(struct test*tree,struct test*curr,char st)
{
	int cmp(struct test*,struct test*, char);
	if(cmp(tree,curr,st))
		if(tree->link1)
			srt(tree->link1,curr,st);
		else
		{
			tree->link1=curr;
			return;
		}
	else
		if(tree->link2)
			srt(tree->link2,curr,st);
		else
		{
			tree->link2=curr;
			return;
		}

}
/*Function to compare the repective values of curr1 and curr2 as per
sort method, Return 1 if curr1>curr2*/
int cmp(struct test*curr1,struct test*curr2,char sort)
{
	switch(sort)
	{
		case 'm':
			if(curr1->mk>curr2->mk)
				return 1;
			else
				return 0;
		case 'r':
			if(curr1->roll>curr2->roll)
				return 1;
			else
				return 0;
		default :
			int i=0;
			while(curr1->name[i]==curr2->name[i])
				if(curr1->name[i]=='\0')
					return 0;
				else
					i++;
			if(curr1->name[i]>curr2->name[i])
				return 1;
			else
				return 0;
	}
}
/*Function to print a Binary Self Referential Structure*/
void prin(struct test*first)
{
	struct test*tree=first;
	if(tree->link1)
		prin(tree->link1);
	printf("%d\t%-20s\t%d\n",tree->roll,tree->name,tree->mk);
	if(tree->link2)
		prin(tree->link2);
	return;
}