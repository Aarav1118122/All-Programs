#include<stdio.h>
#include<conio.h>
#define MAXLINE 10
#define MAXLEN 1000
/*to sort a set of lines lexicographically*/
void main()
{
	int strcmp(char *,char *);
	long int getlines(char *,int *,long int,long int),ln=0;
	int s[MAXLINE],ch=0,no=0,tn,line;
	char str[MAXLEN];
	if(line=getlines(str,s,MAXLEN,MAXLINE))
	{
		for(tn=0;tn<line-1;tn++)
		{
			no=1;
			for(ln=0;ln<line-1;ln++)
			{
				ch=strcmp((str+s[ln]),(str+s[ln+1]));
				if(ch>0)
				{
					int temp;
					temp=s[ln];
					s[ln]=s[ln+1];
					s[ln+1]=temp;
					no=0;
				}
			}
		if(no)
			break;
		}
		for(ln=0;ln<line;ln++)
			printf("%s\n",str+s[ln]);
	}
	else
		printf("Error in the length of the input");
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
long int getlines(char *st,int *pt,long int y,long int z)
{
	long int lines=0,ct=0;
	*pt++=0;	       	    /*sets the first line pointer to 0*/
	while((*st=getchar())!=EOF) /*keeps adding the next character*/
	{                           /*into the array *st */
		ct++;                       /*increments counter*/
		if(*st++=='\n')             /*increments lines if a new line*/
		{                           /*is found also changes the last*/
			*(st-1)='\0';       /*element of the array to '\0'*/
			if((++lines)>z-1)   /*returns error if no of lines*/
				return 0;   /*exceeds max no else sets the*/
			*pt++=ct;           /*line pointer to the next line*/
		}
		if(ct>=y)  	   /*checks if max length of array is*/
			return 0;  /*exceeded and returns error*/
	}
	*st='\0';        /*sets the last element to end of string*/
	return lines+1;  /*returns number of lines - no of '\n' + EOF*/
}