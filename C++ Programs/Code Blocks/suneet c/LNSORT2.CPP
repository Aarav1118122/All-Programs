#include<stdio.h>
#include<alloc.h>
#define MAXLINE 1000
#define MAXLEN 1000
/*Line sort using Pointers*/
void main()
{
	char *str[MAXLINE];
	int strcmp(char *,char *),tn,no,ch=0,line;
	int getlines(char*[],int,int),ln=0;
	void write(char*[],int);
	line=getlines(str,MAXLEN,MAXLINE);
	for(tn=0;tn<line-1;tn++)
	{
		no=1;
		for(ln=0;ln<line-1;ln++)
		{
			ch=strcmp(*(str+ln),*(str+ln+1));
			if(ch>0)
			{
				char *temp;
				temp=str[ln];
				str[ln]=str[ln+1];
				str[ln+1]=temp;
				no=0;
			}
		}
	if(no)
		break;
	}
	write(str,line);
}
int strcmp(char *a,char *b)
{
	while(*a++==*b++)
	{
		if(*(a-1)=='\0')
			return 0;
	}
	return (*(a-1)-*(b-1));
}
int getlines(char *st[],int y,int z)
{
	int lines=0,len=0,get(char*,int);
	char *lin,*ln2;
	lin=(char *)malloc(y);
	while((len=get(lin,y))>=0)
	{
		ln2=(char *)malloc(len);
		ln2=lin;
		st[lines++]=ln2;
		if(lines>=z)
			break;
		lin=(char *)malloc(y);
	}
	return lines;
}
int get(char *pt,int mx)
{
	int ct=0;
	while(ct<mx&&(*pt++=getchar())!='\n'&&*(pt-1)!=EOF)
		ct++;
	if(*(pt-1)=='\n')
	{
		*(pt-1)='\0';
		return ct;
	}
	*(pt-1)='\0';
	return ct-1;
}
void write(char*s[],int nos)
{
	while(nos--)
		printf("%s\n",*s++);
}