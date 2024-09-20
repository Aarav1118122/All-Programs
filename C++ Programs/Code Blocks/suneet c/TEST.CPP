#include<stdio.h>
#include<conio.h>
/*to check the function of pointers increment etc*/
void main()
{
	void test(char*[]);
	char *p[]={"12abc","34def","56ghi","78jkl","90mno"};
	test(p);
}
void test(char*te[])
{
	clrscr();
	printf("\n%c",(*++te)[1]);
	printf("\n%c",(*te++)[3]);
	printf("\n%c",*te[0]);
	printf("\n%s",*te);
}