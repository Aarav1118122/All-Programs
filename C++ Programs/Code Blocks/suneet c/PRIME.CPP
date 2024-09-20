#include <stdio.h>
#include<conio.h>
#define MAX 32000
#define MAXA 16000
/*to calculate a series of prime numbers*/
void main()
{
	int num, div, prim;
	int nos[MAXA],ct;
	clrscr();
	for(ct=1;ct<=3;++ct)
		nos[ct]=ct;
	printf("\nThe Prime numbers are : \n");
	for(num=5;num<=MAX&&ct<MAXA;num+=2)
	{
		prim=1;
		div=3;
		while (num>=(nos[div]*nos[div])&&prim==1)
		{
			if (num%nos[div]==0)
				prim=0;
			++div;
		}
		if (prim)
		{
			printf("%d,\t", num);
			nos[ct++]=num;
		}
	}
	printf("\nThe number of prime numbers are : %d\n",ct);
	do
	{
		printf("Enter the Number ? ");
		scanf("%d",&num);
		flushall();
		prim=0;
		for(ct=2;ct<MAXA&&!prim&&(num>=(nos[ct]*nos[ct]));ct++)
			if(!(num%nos[ct]))
				prim=1;
		if(!prim)
			printf("Prime");
		else
			printf("%d",nos[--ct]);
		printf("\nAny More (Y/N) ?\n");
	}while(getch()=='y');
}