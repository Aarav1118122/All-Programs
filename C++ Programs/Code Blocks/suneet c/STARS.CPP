#include <stdio.h>
/*To Print a pyramid of the required number of Stars-* */
void main()
{
	int num,ct1,ct2;

	printf("\nThe number of lines required : ");
	scanf("%d",&num);
	for (ct1=num;ct1>0;--ct1)
	{
		for(ct2=1;ct2<=num;++ct2)
		{
			if (ct2<ct1)
				printf(" ");
			else
				printf("*");
		}
		printf(" ");
		for(ct2=num;ct2>=ct1;--ct2)
			printf("*");
		printf("\n");
	}
	for(ct1=1;ct1<=num;++ct1)
	{
		for(ct2=1;ct2<=num;++ct2)
		{
			if (ct2<ct1)
				printf(" ");
			else
				printf("*");
		}
		printf(" ");
		for(ct2=num;ct2>=ct1;--ct2)
			printf("*");
		printf("\n");
	}
}