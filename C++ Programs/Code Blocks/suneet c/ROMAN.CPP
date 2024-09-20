//Programme to Print the Roman Numerals
#include<stdio.h>
#include<conio.h>
//Main Module to handle input, size calculation etc
void main()
{
	int num,prin(int,int),siz,els(int,int);
	for(char y='y';y=='y';y=getch())
	{
		clrscr();
		printf("Please Enter a Number between 0 and 4999 : ");
		scanf("%d",&num);
		if(num>=5000||num<0)
		{
			printf("Error : Number out of Limits\n\nAny More ? ");
			continue;
		}
		printf("The Roman Equivalent is : ");
		siz=1;
		while(num>=siz)		//Find the size of the Number to the
			siz*=10;	//Higher Tens.
		if(num>=siz/2)		//Calculate the size of the Number
			siz/=2;		//to the lower Fives
		else			//eg num==15, siz==10
			siz/=10;	//num==90, siz==50.
		if(num<1000&&num!=siz&&num>20)
			num=els(num,siz);	//Check for exception cases
		while(num)
		{
			num=prin(num,siz);	//Print Non exception cases
			if(siz==1000||siz==100)	//Reduce siz to the lower
				siz/=2;		//fives
			else
				siz/=5;
		}
		printf("\n\nAny More ? ");
	}
}
//Print single Digits ie I,II...IX and also 'V's for numbers greater than 10
void one(int num)
{
	char *s[]={"I","II","III","IV","V","VI","VII","VIII","IX"};
	if(num<10)		//Normal if number less than 10
		printf("%s",s[num-1]);
	else			//If number greater than 10 then must
	{			//print V more than once to reduce number
		while(num>5)	//to less than 5 and then print reduced
		{		//number eg 4999 is DDDMMMCCCLLLXXXVVVIV
			putch('V');
			num-=5;
		}
		printf("%s",s[num-1]);
	}
}
//Print the Characters corresponding to the size greater than 10
void sin(int num)
{
	switch(num)		//Print the Characters corresponding
	{			//to the numbers eg 50 - L
		case 10:putch('X');break;
		case 50:putch('L');break;
		case 100:putch('C');break;
		case 500:putch('M');break;
		case 1000:putch('D');break;
	}
}
//Print the Roman Numerals for numbers as per the size
int prin(int num,int siz)
{
	char tr=0;
	if(siz<10)		//print the last digits if siz<10
	{
		one(num);
		return NULL;
	}
	while(num>=siz&&tr<3)
	{
		num-=siz;	//Print the character corresponding to the
		sin(siz);	//siz and reduce num by siz
		tr++;		//maximum tries 3.
	}
	return num;		//return the remainder
}
//Print Numbers which are one character less than another eg 450 - LM
int els(int num,int siz)
{
	if(num>siz*2)		//Calculate siz to the greater fives of the
		siz*=5;		//number eg num==21,siz==50; num==89,siz==100
	else
		siz*=2;
	num=siz-num;
	if(!(num<=10||num==50||num==100))	//return num if not an
		return siz-num;			//exception case
	if(num<10)
		one(num);			//Print the exception case
	else
		sin(num);
	sin(siz);
	return NULL;
}