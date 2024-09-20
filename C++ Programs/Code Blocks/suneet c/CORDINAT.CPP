#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#define SPEED .33 //Speed of Sound in Air in metres/second
double xpos[3],ypos[3],zpos[3];
//Position of the Three Speakers eg xpos[1] is x position of first speaker
double vol1[3]={0.0,33.0,42.9},vol2[3]={33.0,0.0,42.9},vol3[3]={42.9,42.9,0.0};
/*Delay recieved at by the Three Speakers at three positions initiallized for
checking in ms eg vol1[2] is delay at second speaker at first location of robot*/
void graphout(double x, double y)
{
	circle((int)x,(int)y,2);
}
void calc(char ct)
{
	double x0,y0,z0,y1,x1,z1,x2,y2,z2,t[9];
	printf("Enter Location 1 as x,y : ");
	scanf("%f",&x0);
	scanf("%f",&y0);
	printf("Enter Location 2 as x,y : ");
	scanf("%f",&x1);
	scanf("%f",&y1);
	printf("Enter Location 3 as x,y : ");
	scanf("%f",&x2);
	scanf("%f",&y2);
	cleardevice();
	if(ct)
	{
		graphout(x0,y0);
		graphout(x1,y1);
		graphout(x2,y2);
	}
	getch();
	t[2]=2*(x0-x1);
	t[3]=2*(y0-y1);
	t[4]=2*(x0-x2);
	t[5]=2*(y0-y2);
	t[6]=x0*x0-x1*x1+y0*y0-y1*y1;
	t[7]=x0*x0-x2*x2+y0*y0-y2*y2;
	t[8]=t[2]*t[5]-t[3]*t[4];
	for(int sn=0;sn<3;sn++)
	{
		double t0=(double)t[6]+SPEED*SPEED*(vol2[sn]*vol2[sn]-vol1[sn]*vol1[sn]);
		double t1=(double)t[7]+SPEED*SPEED*(vol3[sn]*vol3[sn]-vol1[sn]*vol1[sn]);
		xpos[sn]=(t0*t[5]-t[1]*t[3])/t[8];
		ypos[sn]=(t1*t[2]-t[0]*t[4])/t[8];
	}
}
void check(char ct)
{
	double vl1,vl2,vl3,x,y,t[9];
	printf("\nEnter the Volumes at the speakers as speaker 1,2,3 : ");
	scanf("%g,%g,%g",&vl1,&vl2,&vl3);
	t[2]=2*(xpos[0]-xpos[1]);
	t[3]=2*(ypos[0]-ypos[1]);
	t[4]=2*(xpos[0]-xpos[2]);
	t[5]=2*(ypos[0]-ypos[2]);
	t[6]=xpos[0]*xpos[0]-xpos[1]*xpos[1]+ypos[0]*ypos[0]-ypos[1]*ypos[1];
	t[7]=xpos[0]*xpos[0]-xpos[2]*xpos[2]+ypos[0]*ypos[0]-ypos[2]*ypos[2];
	t[0]=SPEED*SPEED*(vl2*vl2-vl1*vl1)+t[6];
	t[1]=SPEED*SPEED*(vl3*vl3-vl1*vl1)+t[7];
	t[8]=t[2]*t[5]-t[3]*t[4];
	x=(t[0]*t[5]-t[1]*t[3])/t[8];
	y=(t[1]*t[2]-t[0]*t[4])/t[8];
	if(ct)
	{
		cleardevice();
		graphout(x,y);
		getch;
	}
}
void main()
{
	int gdriver = DETECT,gmode;
	char ct=1,tr;
	initgraph(&gdriver, &gmode, "C:\\PROGRA~1\\TC\\BGI");
	if (graphresult())
	{
		printf("Error Opening Graphics Screen : No Graphics will be Displayed\n");
		ct=0;
	}
	calc(ct);
//	for(double sn=0;sn<3;sn++)
//		printf("Speaker Number %ld : %ld, %ld\n",sn+1,xpos[sn],ypos[sn]);
	do
	{
		check(ct);
		printf("\nAny More (y/n) ? ");
		tr=getch();
	}
	while(tr=='y');
	closegraph();
}