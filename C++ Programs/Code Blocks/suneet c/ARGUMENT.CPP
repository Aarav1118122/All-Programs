#include<stdio.h>
#include<conio.h>
/* to check the passing of arguments from one function to another */
void main()
{
	clrscr();
	void test(int arga,char *argb[]);
	char *tst[]={"","Try","Test","Check"};
	int tr=3;
	test(tr,tst);
	getch();
}
void test(int arga,char *argb[])
{
	while(arga--)
		printf("%c\n",(*++argb)[0]);
}