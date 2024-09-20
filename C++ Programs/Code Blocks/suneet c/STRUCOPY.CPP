#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct temp
{
	int tr;
};
struct test
{
	struct temp *tr[5];
};
void main()
{
	struct test *try1,*try2;
	int n;
	clrscr();
	try1=(struct test*)malloc(sizeof(test));
	for(n=0;n<5;n++)
	{
		try1->tr[n]=(struct temp*)malloc(sizeof(temp));
		try1->tr[n]->tr=n*n;
	}
	for(n=0;n<5;n++)
		printf("%p\t%d\t",&try1->tr[n]->tr,try1->tr[n]->tr);
	try2=(struct test*)malloc(sizeof(test));
	*try2=*try1;
	for(n=0;n<5;n++)
		printf("%p\t%d\t",&try2->tr[n]->tr,try2->tr[n]->tr);
	for(n=0;n<5;n++)
	{
		try2->tr[n]=(struct temp*)malloc(sizeof(temp));
		printf("%p\t%d\t",&try2->tr[n]->tr,try2->tr[n]->tr);
	}
	for(n=0;n<5;n++)
	{
		*try2->tr[n]=*try1->tr[n];
		printf("%p\t%d\t",&try2->tr[n]->tr,try2->tr[n]->tr);
	}
	getch();
}