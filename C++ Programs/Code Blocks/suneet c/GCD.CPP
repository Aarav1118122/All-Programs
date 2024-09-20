#include<stdio.h>
/*to calculate the greatest common divisor and least common multiple of*/
/*two numbers*/
void main()
{
	int num1,num2,div,mult,cal;

	div=1;
	cal=2;
	printf("Enter the two numbers : ");
	scanf("%d %d",&num1,&num2);
	while((num1%2)==0 && (num2%2)==0)
	{
		num1=num1/2;
		num2=num2/2;
		div=div*2;
	}
	++cal;
	while(num1>=cal&&num2>=cal)
	{
		if (num1%cal==0 && num2%cal==0)
		{
			div=div*cal;
			num1=num1/cal;
			num2=num2/cal;
		}
		else
			cal+=2;
	}
	printf("\nThe Greatest Common Divisor is %d\n",div);
	printf("the Least Common Multiple is %u\n",div*num1*num2);
}