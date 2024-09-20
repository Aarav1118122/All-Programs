#include<stdio.h>
/*To convert one number from one base to another*/
void main()
{
	int bas1,bas2,mod,mult,num1,num2=0;
	char ask='y';
	while (ask=='y'||ask=='Y')
	{
	mult=1;
	printf("\n\nPlease enter the First Base (Below 10) : ");
	scanf("%d",&bas1);
	printf("Please enter the Second Base (Below 10) : ");
	scanf("%d",&bas2);
	printf("Please enter the Number : ");
	scanf("%d",&num1);
	while(num1>0)
	{
		mod=num1%10;
		num2=num2+mod*mult;
		num1=num1/10;
		mult=mult*bas1;
	}
	mult=1;
	while(num2>0)
	{
		mod=num2%bas2;
		num1=num1+mod*mult;
		num2=num2/bas2;
		mult=mult*10;
	}
	printf("The Number in the second base is : %u",num1);
	printf("\nAny more (Y/N) ? ");
	scanf("%s",&ask);
	}
}
