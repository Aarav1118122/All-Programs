//To count the numbers of vowels, consonants and words in a string
#include<stdio.h>
#include<conio.h>
#define dprint(c) printf(#c" are : %d\n",c)
void main(int argc, char *argv[])
{
	clrscr();
	char *p;
	int consonants=0,vowels=0,words=0,i=0,flag=0;
	while(i++<argc)
	{
		p=argv[i];
		while(*p)
		{
			switch(*p)
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowels++;
					flag=1;
					break;
				case ' ':
					if(flag)
						words++;
					flag=0;
					break;
				default:
					if(*p>='a'&&*p<='z'||*p>='A'&&*p<='Z')
						consonants++;
					flag=1;
					break;
			}
			p++;
		}
		if(flag)
			words++;
		flag=0;
	}
	dprint(consonants);
	dprint(vowels);
	dprint(words);
	printf("Arguments are : %d",argc);
	getch();
}