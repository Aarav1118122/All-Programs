//Matrix Inversion
#include<stdio.h>
#include<matrix.h>
#include<conio.h>
//Main function to handle input of numbers etc
void main()
{
	int num,x,y,temp;
	double**inverse1,**matrix,**test,det,**invertmat(double**,int);
	clrscr();
	printf("Enter the No. of Rows and Columns : ");
	scanf("%d",&num);
	if(num<=0)
		return;
	matrix=creatmat(num,num);
	for(x=0;x<num;x++)
		for(y=0;y<num;y++)
		{
			printf("Enter the Number at position %d,%d : ",x+1,y+1);
			scanf("%d",&temp);
			matrix[x][y]=(double)temp;
		}
	clrscr();
	printf("The Original Matrix is:-");
	dispmat(matrix,num,num,2);
	det=determinant(matrix,num);
	printf("\n\nThe Determinant is %.2f",det);
	if(inverse1=invertmat(matrix,num))
	{
		printf("\n\nThe Inverse Matrix is:-");
		dispmat(inverse1,num,num,2);
		test=multmat(matrix,inverse1,num,num,num);
		printf("\n\nThe Test (Multiplied) Matrix is:-");
		dispmat(test,num,num,2);
		freemat(inverse1,num);
		freemat(test,num);
	}
	else
		printf("\n\nError calculating the Inverse");
	freemat(matrix,num);
	getch();
}