/*Reverses Each word in a string and adds an 'a' at the end*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
void main()
{
	clrscr();
	int ct=0,ct2;
	char *temp,*st;
	st=(char*)malloc(100);
	printf("Please Enter the String (Maxlen=99) : ");
	gets(st);
	while(*st==' '||*st=='\t')
		st++;
	while(*st)
	{
		ct++;
		if(*++st==' '||*st=='\t'||*st=='\0')
		{
			temp=st;
			while(ct--)
				printf("%c",*--st);
			printf("a ");
			st=temp;
		}
	}
	getch();
}
