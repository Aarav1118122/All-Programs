//To Demonstrate Line Clipping inside a window
#include<conio.h>
#include<values.h>
#include<stdlib.h>
#include<graphics.h>
#define LINES 25
int x1,y1,x2,y2;
int bits(int,int);
int check(int,int);
void main()
{
	int gdriver = DETECT,gmode,x,y,p,ct,linex1[LINES],liney1[LINES],linex2[LINES],liney2[LINES],p1bits[LINES],p2bits[LINES],ch[LINES];
	float sl[LINES];
	initgraph(&gdriver, &gmode, "C:\\PROGRA~1\\TC\\BGI");
	if (graphresult())
	{
		getch();
		return;
	}
	x=(getmaxx()-20);
	y=(getmaxy()-20);
	setcolor(getmaxcolor());
	x1=x/2-175;
	y1=y/2-150;
	x2=x/2+175;
	y2=y/2+150;
	rectangle(x1,y1,x2,y2);
	getch();
	for(p=0;p<LINES;p++)
	{
		linex1[p]=random(x);
		liney1[p]=random(y);
		linex2[p]=random(x);
		liney2[p]=random(y);
		line(linex1[p],liney1[p],linex2[p],liney2[p]);
		p1bits[p]=bits(linex1[p],liney1[p]);
		p2bits[p]=bits(linex2[p],liney2[p]);
		ch[p]=check(p1bits[p],p2bits[p]);
		if(liney2[p]==liney1[p])
			sl[p]=MAXFLOAT;
		else
			sl[p]=((float)linex2[p]-linex1[p])/(liney2[p]-liney1[p]);
	}
	getch();
	cleardevice();
	rectangle(x1,y1,x2,y2);
	for(p=0;p<LINES;p++)
		if(ch[p])
		{
			if(ch[p]&1&&sl[p])
			{
				x=x1;
				y=(x1-linex2[p])/sl[p]+liney2[p];
				ct=1;
			}
			else if(ch[p]&2&&sl[p])
			{
				x=x2;
				y=(x2-linex2[p])/sl[p]+liney2[p];
				ct=2;
			}
			else if(ch[p]&4)
			{
				y=y2;
				x=sl[p]*(y2-liney2[p])+linex2[p];
				ct=4;
			}
			else if(ch[p]&8)
			{
				y=y1;
				x=sl[p]*(y1-liney2[p])+linex2[p];
				ct=8;
			}
			if(p1bits[p]&ct)
			{
				linex1[p]=x;
				liney1[p]=y;
				p1bits[p]=bits(linex1[p],liney1[p]);
			}
			else
			{
				linex2[p]=x;
				liney2[p]=y;
				p2bits[p]=bits(linex2[p],liney2[p]);
			}
			ch[p]=check(p1bits[p],p2bits[p]);
			p--;
		}
		else if(!(p1bits[p]|p2bits[p]))
			line(linex1[p],liney1[p],linex2[p],liney2[p]);
	getch();
	closegraph();
}
int bits(int x,int y)
{
	int pbits=0;
	if(x<x1)
		pbits+=1;
	else if(x>x2)
		pbits+=2;
	if(y<y1)
		pbits+=8;
	else if(y>y2)
		pbits+=4;
	return pbits;
}
int check(int p1bits,int p2bits)
{
	if(p1bits&p2bits)
		return NULL;
	return p1bits|p2bits;
}