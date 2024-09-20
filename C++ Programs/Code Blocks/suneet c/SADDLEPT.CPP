//To find the saddle point of a Matrix
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
void main(void)
{
	clrscr();
	int **mat;
	int saddle(int**,int,int,int,int),rows,cols,ct1,ct2;
	void matrix(int**,int,int);
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);
	printf("Enter the number of Columns : ");
	scanf("%d",&cols);
	printf("\n");
	if(!(mat=(int**)malloc(sizeof(int)*rows)))	//Allocate Initial Space for Rows
		return;
	for(ct1=0;ct1<rows;++ct1)
		if(!(*(mat++)=(int*)malloc(sizeof(int)*cols))) //Allocate space to Columns
			return;
	mat-=rows;
	matrix(mat,rows,cols);
	clrscr();
	printf("The Saddle Points are :\n");
	for(ct1=0;ct1<rows;++ct1)
		for(ct2=0;ct2<cols;++ct2)
			if(saddle(mat,ct1,ct2,rows,cols))
				printf("\nPosition %d-%d : %d",ct1+1,ct2+1,*(*(mat+ct1)+ct2));
	getch();
}
//To Input the Numbers to the Matrix
void matrix(int **mats,int row,int col)
{
	clrscr();
	int ct1,ct2;
	char c='n';	//Check the Input Flag
	while(c!='y'&&c!='Y')
	{
		for(ct1=0;ct1<row;++ct1)
		{
			for(ct2=0;ct2<col;++ct2)
			{
				printf("Enter Position %d-%d : ",ct1+1,ct2+1);
				scanf("%d",(*mats)++);
			}
			(*mats)-=col;
			mats++;
		}
		mats-=row;
		for(ct1=0;ct1<row;++ct1)
		{
			for(ct2=0;ct2<col;++ct2)
				printf("\nPosition %d-%d : %d",ct1+1,ct2+1,*((*mats)++));
			(*mats)-=col;
			mats++;
		}
		printf("\n\nIs this correct (Y/N) ? ");
		c=getch();
	}
}
//To check for the saddle point or return 0 if not saddle point
int saddle(int**mats,int row,int col,int rs,int cs)
{
	int ct,num;
	num=*(*(mats+row)+col);
	for(ct=0;ct<cs;++ct)
		if(num>*(*(mats+row)+ct))
			return NULL;
	for(ct=0;ct<rs;++ct)
		if(num<*(*(mats+ct)+col))
			return NULL;
	return !NULL;
}