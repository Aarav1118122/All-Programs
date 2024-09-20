#include<stdio.h>
#include<conio.h>
#define LIMIT 10
//To print a Triangle of Combinations
void main()
{

	clrscr();
	long int ct1,ct2,num,f1,f2,f3,ct,fac(long int);
	for(ct1=1;ct1<=LIMIT;++ct1)
	{
		num=0;
		while(num++<LIMIT-ct1)
			printf("    ");
		f1=fac(ct1);
		for(ct2=1;ct2<=(ct1*2-1);++ct2)
		{
			ct=ct2<ct1?ct2:ct1*2-ct2;
			f2=fac(ct);
			f3=fac(ct1-ct);
			num=f1/(f2*f3);
			printf("%4ld",num);
		}
		printf("\n");
	}
	getch();
}
long int fac(long int ct)
{
	long int y=ct;
	while(--ct>1)
		y*=ct;
	return y?y:1;
}