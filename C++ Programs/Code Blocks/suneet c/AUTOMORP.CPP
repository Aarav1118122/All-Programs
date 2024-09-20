/*To find the automorphic numbers above 10*/
#include<conio.h>
#include<stdio.h>
void main()
{
	clrscr();
	unsigned long int x,y,n,z,a;
	for(a=5;a<=6;a++)
	{
		y=a;
		n=10;
		z=6;
		while(--z)
		{
			for(x=0;x<10;++x)
				if(!((2*n*x*y+y*y-n*x-y)%(10*n)))
				{
					y+=n*x;
					printf("\n%lu",y);
				}
			n*=10;
		}
	}
	getch();
}