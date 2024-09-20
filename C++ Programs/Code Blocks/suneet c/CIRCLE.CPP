//Draw a Circle Algorithm
#include<conio.h>
#include<graphics.h>
void main()
{
	int gdriver = DETECT,gmode,ct,radius,x,y,x1,y1,p;
	initgraph(&gdriver, &gmode, "C:\\PROGRA~1\\TC\\BGI");
	if (graphresult())
	{
		getch();
		return;
	}
	x=(getmaxx()-20)/2;
	y=(getmaxy()-20)/2;
	ct=getmaxcolor();
	y1=radius=x>y?y:x;
	x1=0;
	p=3-2*radius;
	while(x1<=y1)
	{
		{
			int t1=x+x1,t2=x-x1,t3=x+y1,t4=x-y1,t5=y+x1,t6=y-x1,t7=y+y1,t8=y-y1;
			putpixel(t1,t7,ct);
			putpixel(t1,t8,ct);
			putpixel(t2,t7,ct);
			putpixel(t2,t8,ct);
			putpixel(t3,t5,ct);
			putpixel(t3,t6,ct);
			putpixel(t4,t5,ct);
			putpixel(t4,t6,ct);
			out++;
		}
		x1++;
		if(p>0)
		{
			y1--;
			p+=4*(x1-y1)+2;
		}
		else
			p+=4*x1+2;
	}
	getch();
	for(x1=0;x1<=getmaxcolor();x1++)
	{
		setcolor(x1);
		circle(x,y,radius);
		getch();
	}
	closegraph();
}