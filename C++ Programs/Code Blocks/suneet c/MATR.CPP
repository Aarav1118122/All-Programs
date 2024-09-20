#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<matrix.h>
void main()
{
	double**matrix,**inverse,**test;
	int size=0,x,y;
	clrscr();
	printf("Enter the size of the matrix : ");
	scanf("%d",&size);
	if(size<=0)
		return;
	matrix=creatmat(size,size);
	for(x=0;x<size;x++)
		for(y=0;y<size;y++)
			matrix[x][y]=(double)random(10);
	printf("The Original Matrix is:-");
	dispmat(matrix,size,size,0);
	getch();
	if(inverse=invertmat(matrix,size))
	{
		printf("\n\nThe Inverse Matrix is:-");
		dispmat(inverse,size,size,3);
		test=multmat(matrix,inverse,size,size,size);
		getch();
		printf("\n\nThe Test (Multiplied) Matrix is:-");
		dispmat(test,size,size,0);
		freemat(inverse,size);
		freemat(test,size);
	}
	else
		printf("\n\nError calculating the Inverse");
	freemat(matrix,size);
	getch();
}