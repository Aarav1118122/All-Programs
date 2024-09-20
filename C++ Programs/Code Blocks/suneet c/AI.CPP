//Travelling Salesman Problem solved by Artificial Intelligence Algorithm
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define MAXTIME 60
#define CITYNO 50
#define INITAL init
#define MUTAL mutate
#define FILELOC "c:\\docume~1\\sugupta\\mydocu~1\\programs\\cprogr~1\\dat\\city.dat"
//Data Structure to Store the various Routes possible
struct route
{
	int x[CITYNO];
	double val;
}*mu=(struct route*)malloc(sizeof(struct route));
//Data Structure to Store the Coordinates of the various cities
struct city
{
	int x;
	int y;
}citys[CITYNO];
unsigned long trys=0;
//Main Program to call the Randomizing and Mutating functions
void main()
{
	int ct,mult,x=0,y=0,soln=0,opgrph(int,int);
	double origval,calval(struct route*,int);
	struct route*choice,*INITAL(int),*min=NULL;
	void getcty(int),MUTAL(struct route*,int),out(struct route*,int,int,int,int,int);
	clrscr();
	getcty(CITYNO);
	for(ct=0;ct<CITYNO;ct++)
	{
		if(x<citys[ct].x)
			x=citys[ct].x;
		if(y<citys[ct].y)
			y=citys[ct].y;
	}
	mult=opgrph(x,y);
	x=(getmaxx()-x*mult)/2;
	y=(getmaxy()-(40+y*mult))/2;
	clock_t strt=clock(),endt=strt;
	while((clock()-strt)/CLK_TCK<MAXTIME)//&&min->val>600)
	{
		choice=INITAL(CITYNO);
		if(!choice)
			break;
		origval=choice->val=calval(choice,CITYNO);
		for(;;)
		{
			MUTAL(choice,CITYNO);
			if(choice->val<origval)
				origval=choice->val;
			else
				break;
		}
		if(!min||min->val>choice->val)
		{
			soln++;
			free((void*)min);
			min=choice;
			out(min,CITYNO,mult,soln,x,y);
			endt=clock();
		}
		else
			free((void*)choice);
	}
	out(min,CITYNO,mult,0,x,y);
	printf("Minimum Choice is :-\n");
	for(ct=0;ct<CITYNO;ct++)
		printf("%d, ",min->x[ct]);
	printf("%d.\n\nTotal Distance\t\t\t: %.2f units\nTime taken\t\t\t: %g s\nNo of Evaluations\t\t: %lu\nNo of Times Solution Changed\t: %d",min->x[0],min->val,(endt-strt)/CLK_TCK,trys,soln);
	free((void*)mu);
	free((void*)min);
	getch();
}
//Input the City Data
void getcty(int ct)
{
	printf(FILELOC);
	FILE*tst=fopen(FILELOC,"r");
	if(!tst)
	{
		perror("Data Input Error ");
		getch();
		exit(1);
	}
	while(ct--)
		fscanf(tst,"%d %d",&citys[ct].x,&citys[ct].y);
	fclose(tst);
}
//Open the Graphics Screen and Calculate the Multiplicative factor
int opgrph(int maxx,int maxy)
{
	int gdriver = DETECT,gmode,ct,mult,x,y;
	initgraph(&gdriver, &gmode, "C:\\PROGRA~1\\TC\\BGI");
	if (graphresult())
	{
		printf("Error Opening Graphics Screen : No Graphics will be Displayed\n");
		getch();
		return NULL;
	}
	x=(getmaxx()-10)/maxx;
	y=(getmaxy()-40)/maxy;
	setcolor(getmaxcolor());
	return x>y?y:x;
}
//Display the Data in a Graphic Mode
void out(struct route*choice,int cityno,int mult,int soln,int x,int y)
{
	if(!mult)
		return;
	int x0,y0,x1,y1,xmax=getmaxx(),ymax=getmaxy(),ct;
	char string[10];
	cleardevice();
	x1=x0=citys[choice->x[0]-1].x*mult+x;
	y1=y0=citys[choice->x[0]-1].y*mult+y;
	settextstyle(SMALL_FONT,0,0);
	outtextxy(x1-25,y1+8,"Start/Stop");
	moveto(x1,y1);
	outtext(itoa(choice->x[0],string,10));
	for(ct=1;ct<cityno;ct++)
	{
		moveto(x1,y1);
		x1=citys[choice->x[ct]-1].x*mult+x;
		y1=citys[choice->x[ct]-1].y*mult+y;
		lineto(x1,y1);
		outtext(itoa(choice->x[ct],string,10));
	}
	line(x1,y1,x0,y0);
	outtextxy(xmax/2-13,ymax-30,gcvt(choice->val,5,string));
	settextstyle(SMALL_FONT,0,5);
	if(soln)
	{
		moveto(xmax/2-153,ymax-20);
		outtext("The Plot of the Cities and the Route :-");
		outtext(itoa(soln,string,10));
		line(xmax-475,ymax-5,xmax-167,ymax-5);
	}
	else
	{
		moveto(xmax/2-168,ymax-20);
		outtext("The Plot of the Cities and the Route :- Final");
		line(xmax-490,ymax-5,xmax-152,ymax-5);
		getch();
		closegraph();
	}
}
//Algorithm to Calculate the Value(Distance) of the Route
double calval(struct route*choice,int cityno)
{
	int ct,disx,disy;
	double val=0;
	trys++;
	for(ct=1;ct<cityno;ct++)
	{
		disx=citys[choice->x[ct]-1].x-citys[choice->x[ct-1]-1].x;
		disy=citys[choice->x[ct]-1].y-citys[choice->x[ct-1]-1].y;
		val+=sqrt((double)(disx*disx+disy*disy));
	}
	disx=citys[choice->x[ct-1]-1].x-citys[choice->x[0]-1].x;
	disy=citys[choice->x[ct-1]-1].y-citys[choice->x[0]-1].y;
	return val+sqrt((double)(disx*disx+disy*disy));
}
//Mutation Algorithm 1 - One Point Controlled
void mutate(struct route*choice,int cityno)
{
	double calval(struct route*,int);
	int ct1,ct2,ct3;
	*mu=*choice;
	for(ct1=0;ct1<cityno-1;ct1++)
		for(ct2=ct1+1;ct2<cityno;ct2++)
		{
			int num=mu->x[ct1];
			for(ct3=ct1;ct3<ct2;ct3++)
				mu->x[ct3]=mu->x[ct3+1];
			mu->x[ct2]=num;
			if((mu->val=calval(mu,cityno))<choice->val)
				*choice=*mu;
			for(ct3=ct2;ct3>ct1;ct3--)
				mu->x[ct3]=mu->x[ct3-1];
			mu->x[ct1]=num;
		}
}
//Randomize Algorithm to Select an Initial Route
struct route*init(int cityno)
{
	int ct1=0,ct2,nm,flag;
	struct route*nw=(struct route*)calloc(1,sizeof(struct route));
	while(ct1<cityno)
	{
		nm=random(cityno)+1;
		flag=1;
		for(ct2=0;ct2<ct1;ct2++)
			if(nw->x[ct2]==nm)
				flag=0;
		if(flag)
			nw->x[ct1++]=nm;
	}
	return nw;
}
//Minimum Distance Algorithm for Initial route
struct route*init2(int cityno)
{
	static int ct1,ct2,ct3,flag,first=0,disx,disy;
	double dis1,dis2;
	if(first==cityno)
		return NULL;
	struct route*nw=(struct route*)malloc(sizeof(struct route));
	first++;
	nw->x[0]=first;
	for(ct1=1;ct1<cityno;ct1++)
	{
		dis1=0;
		for(ct2=1;ct2<=cityno;ct2++)
		{
			flag=0;
			for(ct3=0;ct3<ct1;ct3++)
				if(ct2==nw->x[ct3])
					flag=1;
			if(flag)
				continue;
			disx=citys[ct2-1].x-citys[nw->x[ct1-1]-1].x;
			disy=citys[ct2-1].y-citys[nw->x[ct1-1]-1].y;
			dis2=sqrt((double)(disx*disx+disy*disy));
			if(!dis1||dis2<dis1)
			{
				dis1=dis2;
				nw->x[ct1]=ct2;
			}
		}
	}
	return nw;
}
//Mutation Algorithm 2 - Two Point Random
void mutate2(struct route*choice,int cityno)
{
	double calval(struct route*,int);
	int ct1=random(cityno),ct2=random(cityno);
	int num=choice->x[ct1];
	choice->x[ct1]=choice->x[ct2];
	choice->x[ct2]=num;
}
//Mutation Algorithm 3 - Cut Paste Random
void mutate3(struct route*choice,int cityno)
{
	int ct1=random(cityno),ct2=0,ct3;
	for(ct3=ct1;ct3<cityno;ct3++)
		mu->x[ct2++]=choice->x[ct3];
	for(ct3=0;ct3<ct1;ct3++)
		mu->x[ct2++]=choice->x[ct3];
	*choice=*mu;
}
//Mutation Algorithm 4 - One Point Random
void mutate4(struct route*choice,int cityno)
{
	int ct1=random(cityno),ct2,num;
	num=choice->x[0];
	for(ct2=0;ct2<ct1;ct2++)
		choice->x[ct2]=choice->x[ct2+1];
	choice->x[ct2]=num;
}
//Mutation Algorithm 5 - Cut Paste Controlled
void mutate5(struct route*choice,int cityno)
{
	int ct1,ct2,ct3,num;
	struct route*mu2=(struct route*)malloc(sizeof(struct route));
	*mu2=*choice;
	for(ct1=0;ct1<cityno;ct1++)
	{
		ct2=0;
		for(ct3=ct1;ct3<cityno;ct3++)
			mu->x[ct2++]=choice->x[ct3];
		for(ct3=0;ct3<ct1;ct3++)
			mu->x[ct2++]=choice->x[ct3];
		mu->val=calval(mu,cityno);
		if(mu2->val>mu->val)
			*mu2=*mu;
	}
	*choice=*mu2;
	free(mu2);
}
//Mutation Algorithm 6 - Two Point Controlled
void mutate6(struct route*choice,int cityno)
{
	double calval(struct route*,int);
	int ct1,ct2;
	*mu=*choice;
	for(ct1=1;ct1<cityno-2;ct1++)
		for(ct2=ct1+1;ct2<cityno-1;ct2++)
		{
			int temp=mu->x[ct1];
			mu->x[ct1]=mu->x[ct2];
			mu->x[ct2]=temp;
			mu->val=calval(mu,cityno);
			if(mu->val<choice->val)
				*choice=*mu;
			mu->x[ct2]=mu->x[ct1];
			mu->x[ct1]=temp;
		}
}