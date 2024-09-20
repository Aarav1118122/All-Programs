/*A Chess Programme by Suneet Gupta*/
#include<dos.h>
#include<time.h>
#include<memory.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<graphics.h>
typedef struct piece/*Each Piece*/
{
	char name;/*name of the piece*/
	int val, posx, posy;/*value of piece and position on board*/
}PIECE;
typedef struct player/*Players*/
{
	int noofpieces/*No of Pieces left*/,kingflag/*Whether Castling permitted or not*/;
	PIECE *pieces[16];/*Individual Pieces*/
}PLAYER;
typedef struct movelist/*Linked List of Moves*/
{
	char move[7];/*Move in Alphabets*/
	struct movelist *next;/*Pointer to Next Move*/
}MOVE;
typedef struct boardpos/*Board Position*/
{
	int colour;/*Colour of Piece*/
	PIECE *pieces;/*Pointer to the Piece*/
}BOARD;
enum vld {FALSE,TRUE} brdflg=FALSE/*Board Change Flag*/;
typedef vld(MOVCHK)(const int,const int,const int,const int);/*Path checking algorithms*/
typedef vld(VALIDATE)(const char*,const int,int*);/*Move Validation Algorithms*/
typedef int(VALIDMOVS)(PIECE*,int*,const int);/*Valid Moves of a Piece*/
typedef void(DRAWPOS)(const int,const int);/*Piece Drawing Algorithms*/
typedef void(DISPLAY)(const int,char**);/*Help and Menu Display*/
PLAYER *play[2]/*The two players*/,*copyplyr(PLAYER*);
BOARD bord[9][9];/*Board Positions*/
MOVCHK checknight,checkstrt,checkdiag;
VALIDATE kingpos,validcastle,majpos,pawnpos;
VALIDMOVS vldmovs,kingvld,rookvld,bishopvld,knightvld,pawnvld;
DRAWPOS drawking,drawpawn,drawrook,drawbishop,drawqueen,drawknight,hlppaus;
DISPLAY helpdisp,drawmenu,drawitms;
vld possmove(PIECE*,const int,const int,const int),validate(char*,const int,int*);
vld gamemenu(),kingshield(const int,const int,const int,const int,const int);
vld validmov(PIECE*,const int,const int,const int),movleft(const int);
int clrflg=2/*Colour of User*/,recur=1/*Level of Recursion*/;
int xplt,yplt,ct/*Board Sizes*/,pnflg/*Pawn Special Move Flag*/;
int bestmov(const int,const int,int*),chkbst(const int,const int,const int*);
int xposition(const char),yposition(const char),evalpos(const int,const vld);
int threatpos(const int,const int,const int),baseval(const char);
void exitscr(),startscr(),compbrk(char*,const vld),hlpscren(const int,const int,char*);
void helpmenu(),mainmenu(),dispmenu(),playgame(),getnewpc(PIECE*,const int,const vld);
void restorpiec(const vld),killmove(const int,const int,const int,const vld);
void deadlock(),matenot(const int),changepos(const int*,const int,const vld);
void lvlmenu(),printmoves(int,MOVE*),clearplc(const int,const int,const vld);
void initialize(),delplyr(PLAYER*),castlemove(const int,const int,const vld);
void optionmenu(),background(const int),makemove(char*,const int*,const int);
void drawboard(),colrmenu(),plyrmenu(),drawpiece(PIECE*,const int,const vld);
void chshelp(),playhelp(),ophelp(),freemov(MOVE*),restorpos(PLAYER*,PLAYER*);
double moves(char*,const int),compmov(char*,const int);
/*The Main Programme*/
vld main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver, &gmode, "BGI");/*Open Graphics Screen*/
	if(graphresult())/*Error*/
	{
		clrscr();
		printf("Error Opening Graphics Screen : Chess Cannot Be Played");
		getch();
		return TRUE;/*Abnormal Termination*/
	}
	startscr();/*Initial Splashup*/
	mainmenu();/*Main Menu*/
	exitscr();/*Exit Screen*/
	closegraph();/*Close Graphics Screen*/
	return FALSE;/*Normal Termination*/
}
/*Starting Splashup Screen*/
void startscr()
{
	int xp,yp,mult,nmve=0;
	cleardevice();
	xplt=getmaxx();/*Max possible x and y coordinates*/
	yplt=getmaxy();
	mult=xplt>yplt?yplt:xplt;/*Maximum size of the Screen*/
	ct=(mult-20)/8;/*Size of a square*/
	xp=xplt/2;/*X and Y positions for the Text*/
	yp=yplt/2-30;
	xplt=(xplt-ct*9)/2+6;/*Board on the Middle of the Screen*/
	yplt=(yplt-ct*9)/2-2;
	do
	{
		settextjustify(CENTER_TEXT,BOTTOM_TEXT);
		switch(nmve%3)/*Colour for Display*/
		{
			case 0:
				setcolor(LIGHTGREEN);
				break;
			case 1:
				setcolor(LIGHTMAGENTA);
				break;
			case 2:
				setcolor(YELLOW);
				break;
		}
		settextstyle(GOTHIC_FONT,HORIZ_DIR,0);/*Splashup Screen Display*/
		setusercharsize(5,2,3,1);
		outtextxy(xp,yp,"CHESS");
		settextstyle(SCRIPT_FONT,HORIZ_DIR,0);
		setusercharsize(1,1,1,1);
		outtextxy(xp,yp+80,"by");
		outtextxy(xp,yp+130,"Suneet Gupta");
		background(nmve++);/*Background Chess Board*/
	}while(!(kbhit()&&getch()));/*Till the Keyboard is Hit & Remove the Character*/
}
/*Draw a Menu with noitm No of Items and Items given as items*/
void drawmenu(const int noitm,char **items)
{
	int nmve=0;
	cleardevice();
	do
	{
		drawitms(noitm,items);/*Draw the Menu*/
		background(nmve++);/*Background Chess Board*/
	}
	while(!kbhit());
}
/*Draw a Menu with noitm No of Items and Items given as items*/
void drawitms(const int noitm,char **items)
{
	int x,y,xp,yp;
	xp=getmaxx()/2;
	yp=getmaxy()/2;
	y=(noitm*40+70)/2;
	setcolor(GREEN);
	rectangle(xp-140,yp-y,xp+140,yp+y);
	rectangle(xp-138,yp-y+2,xp+138,yp+y-2);
	setcolor(LIGHTMAGENTA);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,0);
	setusercharsize(1,1,1,1);
	outtextxy(xp,yp-y+10,items[0]);/*Heading*/
	setcolor(YELLOW);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
	setusercharsize(4,5,4,5);
	yp-=y-20;
	for(x=1;x<=noitm;x++)/*Items*/
		outtextxy(xp-120,yp+x*40,items[x]);
}
/*Back Ground Chess Game*/
void background(const int nmve)
{
	int cflg,colr,change[5];
	vld brd;
	cflg=clrflg;/*Save the Flags*/
	brd=brdflg;
	colr=nmve%2;
	clrflg=5;/*Reset the flags*/
	brdflg=FALSE;
	if(!(nmve%30))/*Clear the Board after every 30 Moves*/
		initialize();
	else
		delay(1000);/*Delay the Next Move*/
	bestmov(colr,0,change);
	changepos(change,colr+1,TRUE);
	clrflg=cflg;/*Restore Flags*/
	brdflg=brd;
}
/*The Main Menu*/
void mainmenu()
{
	int xp,yp;
	char rep,*items[]={"Main Menu","1. Start Game","2. Options","3. Help","4. Exit"};
	for(;;)/*Infinite Loop*/
	{
		drawmenu(4,items);/*Draw the Menu*/
		rep=getch();
		switch(rep)
		{
			case '1': case 13:/*Option 1 or Enter*/
				xplt+=ct+15;/*To Position the Board in Middle Right Corner*/
				cleardevice();/*Cleardevice*/
				initialize();/*Initialize the Board*/
				playgame();/*Start the Game*/
				xplt-=ct+15;/*Correct Position*/
				break;
			case '2':/*Option 2*/
				optionmenu();
				break;
			case '3':/*Option 3*/
				helpmenu();
				break;
			case '4': case 27:/*Option 4 or Escape*/
				return;
		}
	}
}
/*Options Menu*/
void optionmenu()
{
	char rep,*items[]={"Options Menu","1. No of Players","2. Change Colour","3. Computer Level","4. Think Moves","5. Previous Menu"};
	for(;;)/*Infinite Loop*/
	{
		drawmenu(5,items);
		rep=getch();
		switch(rep)
		{
			case '1':/*Option 1*/
				plyrmenu();
				break;
			case '2':/*Option 2*/
				if(!(clrflg==0||clrflg==5))/*Single Player Mode*/
					colrmenu();
				break;
			case '3':/*Option 3*/
				if(clrflg!=0)/*Double Player Mode*/
					lvlmenu();
				break;
			case '4':/*Option 4*/
				if(clrflg!=0)/*Double Player Mode*/
					dispmenu();
				break;
			case '5': case 27:/*Option 5 or Escape*/
				return;
		}
	}
}
/*Number of Players*/
void plyrmenu()
{
	char rep,*items[]={"No of Players","0. Zero","1. One (Default)","2. Two"};
	for(;;)/*Infinite Loop*/
	{
		drawmenu(3,items);
		rep=getch();
		switch(rep)
		{
			case '0':/*Option 0*/
				clrflg=5;/*Both Players Human*/
				return;
			case '1': case 13:/*Option 1 or Enter*/
				if(clrflg==0||clrflg==5)/*Previous Colour Not Set*/
					colrmenu();/*Call Colour Menu*/
				return;
			case '2':/*Option 2*/
				clrflg=0;/*Both Players Computer*/
				return;
			case 27:/*Escape*/
				return;
		}
	}
}
/*Computer Colour*/
void colrmenu()
{
	char rep,*items[]={"Player Colour","1. White (Default)","2. Black"};
	for(;;)/*Infinite Loop*/
	{
		drawmenu(2,items);
		rep=getch();
		switch(rep)
		{
			case '1': case 13:/*Option 1 or Enter*/
				clrflg=2;/*White Player Human*/
				return;
			case '2':/*Option 2*/
				clrflg=3;/*Black Player Human*/
				return;
			case 27:/*Escape*/
				if(clrflg==2||clrflg==3)
					return;
		}
	}
}
/*Think Ahead Level*/
void lvlmenu()
{
	char rep,*items[]={"Computer Level","   Enter a Value","    from 1 to 3"};
	for(;;)/*Infinite Loop*/
	{
		drawmenu(2,items);
		rep=getch();
		if(rep==27)/*Escape*/
			return;
		if(rep<'1'||rep>'3')
			continue;
		recur=rep-'1';
		return;
	}
}
/*Display Think Moves*/
void dispmenu()
{
	char rep,*items[]={"Think Moves","1. Display","2. Don't Display"};
	for(;;)/*Infinite Loop*/
	{
		drawmenu(2,items);
		rep=getch();
		switch(rep)
		{
			case '1':/*Option 1*/
				brdflg=TRUE;/*Think Moves Displayed*/
				return;
			case '2':/*Option 2*/
				brdflg=FALSE;/*Think Moves not Displayed*/
				return;
			case 27:/*Escape*/
				return;
		}
	}
}
/*Notify Deadlock*/
void deadlock()
{
	char *items[]={"StaleMate Draw","   No Valid Move"};
	drawitms(1,items);
	while(kbhit()&&getch());/*Flush the Input Stream*/
	getch();
}
/*Notify Mate*/
void matenot(const int colr)
{
	char *items[]={"Check Mate","               "};
	strcpy(items[1],colr?"     Black Wins":"     White Wins");
	drawitms(1,items);
	while(kbhit()&&getch());/*Flush the Input Stream*/
	getch();
}
/*Exit Screen*/
void exitscr()
{
	char *items[]={"Thank You","     Au Revoir"};
	cleardevice();
	drawitms(1,items);
	getch();
}
/*Help Menu*/
void helpmenu()
{
	char rep,*items[]={"Help Menu","1. About Chess","2. Options Help","3. Playing the Game","4. Previous Menu"};
	for(;;)/*Infinite Loop*/
	{
		drawmenu(4,items);
		rep=getch();
		switch(rep)
		{
			case '1':/*Option 1 About Chess*/
				chshelp();
				break;
			case '2':/*Option 2 Options Help*/
				ophelp();
				break;
			case '3':/*Option 3 Playing the Game*/
				playhelp();
				break;
			case '4': case 27:/*Option 3 or Escape Previous Menu*/
				return;
		}
	}
}
/*Print the Help Screen*/
void hlpdisp(const int nolines,char **lines)
{
	int xp,yp,len,frm,prn,lpr,xmax,ymax;
	double fac;
	char *ln;
	xmax=getmaxx();
	ymax=getmaxy();
	hlpscren(xmax,ymax,lines[0]);/*Print Outline and Heading*/
	yp=20;/*Starting Line*/
	fac=textwidth(lines[0])/(double)xmax;/*No of Lines to Split Into*/
	prn=strlen(lines[0])/fac-2;/*Max Length of Line*/
	for(xp=1;xp<=nolines;xp++)
	{
		yp+=15;/*Gap Between Paragraphs*/
		frm=0;/*Starting Position to Copy Line*/
		len=strlen(lines[xp]);/*Length of Para*/
		ln=(char*)malloc(prn+1);/*Line to Print*/
		while(frm<len)/*Starting Position is Less than the Length*/
		{
			if(yp>ymax-40)/*y position exceeds screen length*/
			{
				hlppaus(xmax,ymax);/*Pause*/
				hlpscren(xmax,ymax,lines[0]);/*Redraw Screen*/
				yp=35;/*Reset y position*/
			}
			lpr=prn;/*Line to Print Length*/
			if(len-frm>prn)/*Para left longer than max length*/
				while(!isspace(lines[xp][frm+lpr]))
					lpr--;/*Find Last Space in Line to Print*/
			strncpy(ln,lines[xp]+frm,lpr);/*Copy Line*/
			ln[lpr]='\0';/*Terminate with Null*/
			outtextxy(20,yp,ln);/*Print the Line*/
			yp+=textheight(ln)+5;/*Add to y position*/
			frm+=++lpr;/*Increment Starting Position*/
		}
		free(ln);
	}
	hlppaus(xmax,ymax);
}
/*Pause in Help Screen*/
void hlppaus(const int xmax,const int ymax)
{
	settextjustify(CENTER_TEXT,TOP_TEXT);
	setcolor(LIGHTMAGENTA);
	outtextxy(xmax/2,ymax-25,"Press Any Key to Continue");
	while(kbhit()&&getch());/*Flush the Input Stream*/
	getch();/*Pause*/
}
/*Draw Help Screen Outline and Heading*/
void hlpscren(const int xmax,const int ymax, char *head)
{
	cleardevice();
	settextstyle(SMALL_FONT,HORIZ_DIR,0);
	setusercharsize(3,2,3,2);
	setcolor(LIGHTGREEN);
	rectangle(0,0,xmax,ymax);/*Outline*/
	rectangle(2,2,xmax-2,ymax-2);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	setcolor(LIGHTMAGENTA);
	outtextxy(xmax/2,10,head);/*Heading*/
	settextjustify(LEFT_TEXT,TOP_TEXT);/*For Help*/
	setcolor(YELLOW);
}
/*Chess Help*/
void chshelp()
{
	char *lines[]={"ABOUT CHESS","Chess is an ancient game invented in India centuries ago by a Bhramin scholar. It is a game with simple rules played by two people on a Black and White Checkered Board with 16 Pieces each.",
	"The object of the game is to position your pieces such that the opposite King is threatened and there is no valid move for the opposite player to protect it. This is known as Check Mate. Opposite pieces can be killed by making a legal move to the square they currently occupy.",
	"The first move is by the White pieces. The legal moves for the pieces are as follows -:",
	"King - One square in any direction straight or diagonally. Castling is permitted with the Rook if there has been no move by the either the King or the Rook.",
	"Queen - Any number of squares in any direction without jumping over another piece.",
	"Rook - Any number of squares in straight direction without jumping.",
	"Bishop - Any number of squares in diagonal direction without jumping.",
	"Knight - Two and a half squares exactly in any direction and is the only piece that can jump over other pieces.",
	"Pawn - Single move forward except possible double move from first rank without jumping over any peice. The Kill move is a single square and diagonal. A pawn on the last rank of the opposite colour is converted to the desired major piece.",
	"For more details about how to play the game consult any Chess Book or any of your friends who knows the game.",
	"Happy Playings. For any suggestions email to Suneet Gupta at guptasuneet2@yahoo.com."};
	hlpdisp(11,lines);
}
/*Options Help*/
void ophelp()
{
	char *lines[]={"OPTIONS HELP","The Main Menu offers options to start a new game with the current settings or to change the various settings for the game. Options can be selected by the Number keys as indicated against them.",
	"This game can be played by Two Players against each other, a Single Player against the Computer, or the computer can play for both sides.",
	"In Single Player mode your colour can be selected as White or Black.",
	"The Computer Level can be selected from 1 to 3. Level 3 is pretty slow on older (Read Pentium II) computers with around 5 mins a move and I recommend Level 1 as the fastest and best.",
	"You can also opt to display the moves of the Computer as it thinks them through. This will also slow down the game.",
	"The Default Settings are Single Player playing with White against the Computer at Level 2 without displaying the think moves.",
	"The White Pieces are coloured Light Blue and the Black Pieces are Red.",
	"Pressing Escape in the Middle of a Game gives the options to Continue or Abandon the game or to switch colours with the computer (only in single player mode)."};
	hlpdisp(8,lines);
}
/*Playing the Game Help*/
void playhelp()
{
	char *lines[]={"PLAYING THE GAME","The Moves can be entered by the Player only in the Text Mode as per the Standard Chess Notation. Any Invalid Moves are rejected by the computer.",
	"The moves may be entered as follows -:",
	"1. Pieces are selected by entering the Piece Prefix to the Move. These are (K)ing, (Q)ueen, (R)ook, (B)ishop, K(n)ight and (P)awn. The pawn prefix is optional.",
	"2. The new positon of the piece is selected by entering the square number as per the rank and file. The Files are numbered from \'a\' to \'h\' starting from the left and the Ranks are numbered from 1 to 8 starting from the white side.",
	"3. If Two pieces of the same name are moving to the same square then they must be distinguished from each other by entering their present square rank or file, failing which the move will be rejected. Identifying rank or file is not necessary if only a single piece with the same prefix can make the possible move, but will not cause rejection. Entering both, the rank and file number will also cause rejection of the move.",
	"4. The previous file number is necessary for a pawn making a kill move diagonally to the side file. The file number is not needed in a straight move and will cause rejection.",
	"5. The x or Kill sign can be entered but is optional. If the sign is entered and there is no kill possible then the move will be rejected.",
	"6. The Squares or Prefixes can be entered in Capitals or in Lower case. A move starting with \'b\' will be assumed to be a Pawn move first and that with \'B\' a Bishop move. However both possibilities will be tested before rejecting the move.",
	"7. Castling Moves are entered by the 0-0 convention, as explained in the examples.",
	"examples -:",
	"Qa6 -> Move Queen to a6",
	"qeA6 -> Move Queen on file e to a6",
	"qk3 -> Invalid Move",
	"nXf3 -> Kill move by Knight to f3",
	"N5xf3 -> Kill Move by Knight on rank 5 to f3",
	"Nfx -> Invalid Move",
	"pd4 -> Pawn moves to d4",
	"d4 -> Pawn moves to d4",
	"k8 -> Invalid Move",
	"eD5 -> Kill Move by pawn of file e to d4",
	"ee5 -> Invalid Move",
	"bc4 -> First Assumed kill move by pawn to c4 and then move by bishop",
	"Bc4 -> First Assumed move by bishop to c4 and then kill move by pawn",
	"0-0 -> King Side Castling",
	"0-0-0 -> Queen Side Castling",
	"0-0- -> Invalid Move"};
	hlpdisp(26,lines);
}
/*Menu on Hitting Escape*/
vld gamemenu()
{
	char rep='\0',*items[]={"Game Menu","1. Continue","2. Abandon Game","3. Help","4. Switch Colours"};
	drawitms(4,items);/*Draw the Menu*/
	for(;;)/*Infinite Loop*/
		switch(rep)
		{
			case '2': case 27:/*Option 2 or Escape Abandon Game*/
				return TRUE;
			case '3':/*Option 3 Help Fall Through to Next Case*/
				chshelp();/*About Chess*/
				playhelp();/*Playing the Game*/
			case '1': case 13:/*Option 1 or Enter Resume Game*/
				return FALSE;
			case '4':/*Option 4 Switch Colours*/
				if(clrflg==2||clrflg==3)
				{
					clrflg=5-clrflg;/*Switch Colours*/
					return FALSE;
				}/*else Ask Choice Again*/
			default:
				rep=getch();
				break;
		}
}
/*Draw the Chess Board*/
void drawboard()
{
	int x,mult,xp,yp;
	char pos[2]={'\0','\0'};
	mult=ct*8;
	xp=xplt+ct/2;/*Remove Middling Corection*/
	yp=yplt+ct/2;
	setcolor(WHITE);/*White for Lines*/
	setlinestyle(SOLID_LINE,1,NORM_WIDTH);/*For All Drawings*/
	rectangle(xp,yp,xp+mult,yp+mult);/*Board*/
	setusercharsize(5,12,5,12);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,0);
	for(x=1;x<9;x++)
	{
		line(xp,yp+ct*x,xp+mult,yp+ct*x);
		line(xp+ct*x,yp,xp+ct*x,yp+mult);
		pos[0]='a'+x-1;
		outtextxy(xplt+x*ct,yp+mult+5,pos);
		pos[0]='9'-x;
		outtextxy(xplt+20,yplt+ct*x,pos);
	}
}
/*Initialize the Playing Board*/
void initialize()
{
	int x,y,y1,y2;
	PLAYER *temp;/*Temporary Variable for initial initialization before assigning to array of players*/
	PIECE *tmp;
	drawboard();/*Draw the Board*/
	for(x=1;x<9;x++)/*Initialize the Board Positions*/
	{
		for(y=1;y<9;y++)
			clearplc(x,y,TRUE);/*Clear Board Positions*/
		bord[x][0].pieces=NULL;
		bord[x][0].colour=0;
		bord[0][x].pieces=NULL;
		bord[0][x].colour=0;
	}
	for(y=0;y<2;y++)/*Initialize the pieces*/
	{
		y1=y?8:1;/*Major Pieces' Row*/
		y2=y?7:2;/*Pawns' Row*/
		temp=(PLAYER*)malloc(sizeof(PLAYER));/*Allocate Memory*/
		temp->noofpieces=16;/*No of Initial Pieces*/
		temp->kingflag=7;/*Castling permitted Both Sides*/
		for(x=0;x<16;x++)/*Allocate memory for each piece*/
			temp->pieces[x]=(PIECE*)malloc(sizeof(PIECE));
		/*Names of the Pieces*/
		temp->pieces[0]->name='k';
		temp->pieces[1]->name='q';
		temp->pieces[2]->name='r';
		temp->pieces[3]->name='r';
		temp->pieces[4]->name='b';
		temp->pieces[5]->name='b';
		temp->pieces[6]->name='n';
		temp->pieces[7]->name='n';
		/*Piece Positions in x*/
		temp->pieces[0]->posx=5;
		temp->pieces[1]->posx=4;
		temp->pieces[2]->posx=1;
		temp->pieces[3]->posx=8;
		temp->pieces[4]->posx=3;
		temp->pieces[5]->posx=6;
		temp->pieces[6]->posx=2;
		temp->pieces[7]->posx=7;
		for(x=0;x<8;x++)/*Piece Positions in y*/
		{
			tmp=temp->pieces[x];
			tmp->posy=y1;
			tmp->val=baseval(tmp->name);
			drawpiece(tmp,y,TRUE);
		}
		for(x=8;x<16;x++)/*Pawn values and positions*/
		{
			tmp=temp->pieces[x];
			tmp->name='p';
			tmp->val=20;
			tmp->posx=x-7;
			tmp->posy=y2;
			drawpiece(tmp,y,TRUE);
		}
		play[y]=temp;/*Assign temp to the player*/
	}
}
/*Draw a Piece tmp of colour colr*/
void drawpiece(PIECE *tmp,const int colr,const vld flg)
{
	int xp,yp;
	xp=tmp->posx;
	yp=tmp->posy;
	bord[xp][yp].colour=colr+1;
	bord[xp][yp].pieces=tmp;
	if(flg==FALSE)/*If Flag is Zero No change to the Board*/
		return;
	setcolor(colr?RED:CYAN);/*Cyan for White and Red for Black Pieces*/
	setfillstyle(SOLID_FILL,colr?LIGHTRED:LIGHTCYAN);/*Fill Pieces*/
	switch(tmp->name)/*Draw the piece in its square. Default-Piece Killed*/
	{
		case'k':/*King*/
			drawking(xplt+ct*xp,yplt+ct*(9-yp));
			break;
		case'q':/*Queen*/
			drawqueen(xplt+ct*xp,yplt+ct*(9-yp));
			break;
		case'r':/*Rook*/
			drawrook(xplt+ct*xp,yplt+ct*(9-yp));
			break;
		case'b':/*Bishop*/
			drawbishop(xplt+ct*xp,yplt+ct*(9-yp));
			break;
		case'n':/*Knight*/
			drawknight(xplt+ct*xp,yplt+ct*(9-yp));
			break;
		case'p':/*Pawn*/
			drawpawn(xplt+ct*xp,yplt+ct*(9-yp));
			break;
	}
}
/*Clear a Place xp,yp*/
void clearplc(const int xp,const int yp,const vld flg)
{
	bord[xp][yp].colour=0;
	bord[xp][yp].pieces=NULL;
	if(flg==FALSE)/*If Flag is Zero No change to the Board*/
		return;
	if((xp+yp)%2)
		setfillstyle(SOLID_FILL,DARKGRAY);/*Fill in the White Squares with Grey*/
	else
		setfillstyle(SOLID_FILL,BLACK);/*Fill in the Black Squares*/
	bar(xplt+xp*ct-ct/2,yplt+(9-yp)*ct-ct/2,xplt+xp*ct+ct/2-1,yplt+(9-yp)*ct+ct/2-1);
}
/*Draw the King*/
void drawking(const int posx,const int posy)
{
	int num=7,points[14];
	bar3d(posx-8,posy+14,posx+8,posy+17,0,0);
	bar3d(posx-5,posy-5,posx+5,posy+14,0,0);
	bar3d(posx-7,posy-5,posx+7,posy-8,0,0);
	points[0]=posx-7; points[1]=posy-8;
	points[2]=posx-7; points[3]=posy-14;
	points[4]=posx-4; points[5]=posy-8;
	points[6]=posx; points[7]=posy-18;
	points[8]=posx+4; points[9]=posy-8;
	points[10]=posx+7; points[11]=posy-14;
	points[12]=posx+7; points[13]=posy-8;
	fillpoly(num,points);
	fillellipse(posx,posy-19,1,1);
}
/*Draw the Queen*/
void drawqueen(const int posx,const int posy)
{
	int num=6,points[12];
	bar3d(posx-8,posy+14,posx+8,posy+17,0,0);
	bar3d(posx-5,posy-5,posx+5,posy+14,0,0);
	bar3d(posx-7,posy-5,posx+7,posy-8,0,0);
	points[0]=posx-7; points[1]=posy-8;
	points[2]=posx-7; points[3]=posy-14;
	points[4]=posx-4; points[5]=posy-8;
	points[6]=posx+4; points[7]=posy-8;
	points[8]=posx+7; points[9]=posy-14;
	points[10]=posx+7; points[11]=posy-8;
	fillpoly(num,points);
	fillellipse(posx,posy-11,3,3);
}
/*Draw the Rook*/
void drawrook(const int posx,const int posy)
{
	bar3d(posx-7,posy+15,posx+7,posy+12,0,0);
	bar3d(posx-5,posy-8,posx+5,posy+12,0,0);
	bar3d(posx-6,posy-8,posx+6,posy-12,0,0);
}
/*Draw the Bishop*/
void drawbishop(const int posx,const int posy)
{
	int num=3,points[6];
	bar3d(posx-7,posy+15,posx+7,posy+12,0,0);
	bar3d(posx-5,posy-5,posx+5,posy+12,0,0);
	points[0]=posx+5; points[1]=posy-5;
	points[2]=posx; points[3]=posy-12;
	points[4]=posx-5; points[5]=posy-5;
	fillpoly(num,points);
}
/*Draw the Knight*/
void drawknight(const int posx,const int posy)
{
	int num=5,points[10];
	bar3d(posx-7,posy+15,posx+7,posy+12,0,0);
	points[0]=posx-5; points[1]=posy+12;
	points[2]=posx-5; points[3]=posy-12;
	points[4]=posx+6; points[5]=posy-8;
	points[6]=posx+2; points[7]=posy-2;
	points[8]=posx+4; points[9]=posy+12;
	fillpoly(num,points);
	pieslice(posx+2,posy-7,0,360,1);
}
/*Draw the Pawn*/
void drawpawn(const int posx,const int posy)
{
	int num=3,points[6];
	bar3d(posx-5,posy+9,posx+5,posy+11,0,0);
	points[0]=posx-4; points[1]=posy+9;
	points[2]=posx+4; points[3]=posy+9;
	points[4]=posx; points[5]=posy-5;
	fillpoly(num,points);
	fillellipse(posx,posy-7,2,2);
}
/*Play the Game*/
void playgame()
{
	MOVE *move,*next,*first;
	int x=0/*Move Count*/;
	vld flg=FALSE/*Exit Flag*/;
	char mov[7];/*Move*/
	double tim[]={0,0};/*Time Taken By Each Side*/
	first=(MOVE*)malloc(sizeof(MOVE));/*Allocate Memory to First Move*/
	first->next=NULL;
	first->move[0]='\0';/*Next Move Blank*/
	move=first;/*Linked List*/
	gotoxy(1,1);
	printf("\r\tMoves\n");
	do
	{
		printmoves(x-22,first);/*Print the Last 22 Moves*/
		gotoxy(1,16);
		printf("Position/Pieces/Time\nW: %d/%d/%.0fs \nB: %d/%d/%.0fs ",evalpos(0,TRUE),play[0]->noofpieces,tim[0],evalpos(1,TRUE),play[1]->noofpieces,tim[1]);
		if(clrflg%(x%2+2))/*Computer Colour*/
			tim[x%2]+=compmov(mov,x%2+1);/*Computer Move*/
		else
			tim[x%2]+=moves(mov,x%2+1);/*User Move*/
		if(!strcmp(mov,""))/*Resume Game*/
			continue;
		if(!strcmp(mov,"EXIT"))/*Exit Flag*/
			flg=TRUE;/*Exit*/
		else if(!strcmp(mov,"MATE"))/*Mate*/
		{
			matenot(x%2);/*Check Mate for Opposite Colour*/
			flg=TRUE;/*Exit*/
		}
		else if(!strcmp(mov,"LOCK"))/*Dead Lock*/
		{
			deadlock();/*Dead Lock*/
			flg=TRUE;/*Exit*/
		}
		else
		{
			strcpy(move->move,mov);/*Copy Move to the Move List*/
			x++;/*Increment Move Count*/
			next=(MOVE*)malloc(sizeof(MOVE));/*Next Move*/
			next->next=NULL;/*Linked List*/
			next->move[0]='\0';/*Next Move Blank*/
			move->next=next;
			move=move->next;
		}
	}while(flg==FALSE);/*Continue till Exit Flag*/
	freemov(first);/*Free the Moves' Link List*/
}
/*Print the Moves from Number frmno*/
void printmoves(int frmno,MOVE *first)
{
	MOVE *move;
	int ln=3,/*Line Number*/x=2;/*Count of Moves*/
	for(move=first;move;move=move->next)/*Follow Linked List*/
	{
		x++;
		if(frmno-->0)/*Continue Till the last moves are reached*/
			continue;
		if(x%2)/*If Odd - White Move*/
		{
			gotoxy(1,ln);
			printf("                   \r");/*Clear Row*/
			printf("%d. ",x/2);/*New Line and Move Number*/
		}
		else/*Even - Black Move*/
			gotoxy(12,ln++);
		printf("%s",move->move);/*On Same Line*/
	}
}
/*Free the Memory of the Move List*/
void freemov(MOVE *first)
{
	MOVE *move;
	while(first)
	{
		move=first->next;
		free(first);/*Deallocate the Memory*/
		first=move;
	}
}
/*Escape Pressed During Play*/
void compbrk(char *move,const vld flg)
{
	if(gamemenu()==TRUE)
	{
		strcpy(move,"EXIT");/*Exit Flag*/
		return;
	}
	if(flg==TRUE)/*Only if Escape During Player Move*/
		strcpy(move,"");/*Resume Game*/
	cleardevice();
	drawboard();/*Redraw the Board*/
	restorpiec(TRUE);/*Restore the Pieces*/
	gotoxy(1,1);
	printf("\r\tMoves\n");/*Print the Title*/
}
/*Computer Move*/
double compmov(char *mov,const int colr)
{
	int pos,change[5];
	clock_t tim=clock();
	bestmov(colr-1,recur,change);
	tim=clock()-tim;
	changepos(change,colr,TRUE);
	makemove(mov,change,colr);
	if(kbhit()&&getch()==27)/*Key Pressed in Computer Play*/
		compbrk(mov,FALSE);
	return tim/CLK_TCK;
}
/*Input the moves from the User Perform elementary error checking and then move the Piece after Full Validation*/
double moves(char *movs,const int colr)
{
	int num,change[5]/*Array to get Standard Move Info*/;
	vld valid=FALSE;
	char move;
	clock_t tim=clock();
	for(;;)/*Infinite Loop*/
	{
		gotoxy(1,20);
		printf("\rNext Move(%c):\t    \b\b\b\b\b\b",colr-1?'B':'W');
		for(num=0;num<6;num++)/*Get Move letters max six*/
		{
			move=getch();/*Get Keypress*/
			if(move=='\r')/*Enter key pressed*/
			{
				move=movs[num-1];/*Last Key entered in move(for later use)*/
				break;
			}
			if(move=='\b'&&num!=0)/*Backspace after the first character*/
			{
				num-=2;
				printf("\b \b");
				continue;
			}
			switch(move)
			{
				case 'a': case 'A': case 'b': case 'B': case 'c':
				case 'C': case 'd': case 'D': case 'e': case 'E':
				case 'f': case 'F': case 'g': case 'G': case 'h':
				case 'H': case 'k': case 'K': case 'q': case 'Q':
				case 'n': case 'N': case 'r': case 'R': case 'p':
				case 'P': case 'X': case 'x': case '0': case '1':
				case '2': case '3': case '4': case '5': case '6':
				case '7': case '8': case '-':
				/*Only valid Keystrokes accepted*/
					movs[num]=move;
					printf("%c",move);
					break;
				case 27:/*Escape*/
					tim=clock()-tim;
					compbrk(movs,TRUE);
					return tim/CLK_TCK;
				default:/*Invalid Move Key Pressed*/
					num--;
					break;
			}
		}
		movs[num]='\0';/*Terminate string with NULL*/
		if(!strncmp("0-0",movs,3)||isalpha(movs[0])&&isdigit(move))/*Compare with castling moves or First letter alphabet and Last letter number*/
			valid=validate(movs,colr,change);/*Validate move*/
		if(valid==TRUE)/*Valid Move*/
			break;
		sound(110);/*Beep*/
		delay(200);
		nosound();
		printf("\nInvalid Move");/*Error Message*/
		getch();/*Pause*/
		printf("\r\t\t");/*Clear Error Message*/
	}
	tim=clock()-tim;
	changepos(change,colr,TRUE);/*Make the move in the data*/
	makemove(movs,change,colr);/*Get the Standardized string representation of the Move*/
	printf("\r\t\t   \r");/*Clear Row*/
	return tim/CLK_TCK;
}
/*Validate the Moves for correctness as per Chess Rules*/
vld validate(char *mov,const int colr,int *change)
{
	vld valid;
	switch(mov[0])/*Validate the Moves as per the piece being moved*/
	{
		case '0':/*Castling*/
			valid=validcastle(mov,colr,change);
			break;
		case 'k': case 'K':/*King*/
			valid=kingpos(mov,colr,change);
			break;
		case 'Q': case 'R': case 'N':/*Major Capital Letter*/
			mov[0]+='a'-'A';/*Change to Small letter and fall through*/
		case 'q': case 'r': case 'n': /*Major Small Letter*/
			valid=majpos(mov,colr,change);
			break;
		case 'B':/*Bishop First for capital B*/
			mov[0]+='a'-'A';/*Change to Small Letter*/
			valid=majpos(mov,colr,change);
			if(!valid)/*Assume Pawn move if Bishop move not valid*/
				valid=pawnpos(mov,colr,change);
			break;
		case 'b':/*Pawn First for small B*/
			valid=pawnpos(mov,colr,change);
			if(!valid)/*Assume Bishop move if Pawn move not valid*/
				valid=majpos(mov,colr,change);
			break;
		case 'p': case 'P':/*Pawn*/
			valid=pawnpos(mov+1,colr,change);
			break;
		default:/*Assume Pawn as Default*/
			valid=pawnpos(mov,colr,change);
			break;
	}
	return valid;
}
/*Validate King Move*/
vld kingpos(const char *mov,const int colr,int *change)
{
	int xpos=0,ypos=0,temp,tm,brd;
	PIECE *tmp;
	tm=mov[1];/*(Temporary use of variable)*/
	if(tm=='x'||tm=='X')/*Disregard Kill Sign*/
		temp=2;
	else
		temp=1;
	if(mov[temp+2])/*String Longer than expected*/
		return FALSE;
	tmp=play[colr-1]->pieces[0];/*King*/
	ypos=yposition(mov[temp+1]);/*New y Position of King*/
	xpos=xposition(mov[temp]);/*New x Position of King*/
	brd=bord[xpos][ypos].colour;
	if(brd==colr)/*New position already occupied by own piece*/
		return FALSE;
	if(temp==2&&!brd)/*Invalid Kill Move*/
		return FALSE;
	if(validmov(tmp,xpos,ypos,colr)==FALSE)
		return FALSE;
	change[0]=brd;/*Opposite piece killed or not*/
	change[1]=xpos;/*New x position*/
	change[2]=ypos;/*New y position*/
	change[3]=0;/*Piece Number*/
	change[4]=0;/*Position not necessary in the move*/
	return TRUE;
}
/*Validate Castling Moves*/
vld validcastle(const char *mov,const int colr,int *change)
{
	int x,typ,valid;
	typ=colr-1?8:1;/*First File for the Colour*/
	valid=play[colr-1]->kingflag;/*Castling Flag-7 Both sides permissible*/
	if(!strcmp(mov,"0-0-0")&&valid%3)/*Compare move and Castling Flag '4' Only Queen side*/
	{
		if(checkstrt(1,typ,5,typ)==FALSE)/*Check Path Clear*/
			return FALSE;
		for(x=3;x<6;x++)/*Check Intermediate Positions of King not threatened*/
			if(threatpos(x,typ,colr)%16)
				return FALSE;
		for(x=0;x<4;x++)/*Castling Move*/
			change[x]=0;
		change[4]=1;/*Queen Castling*/
		return TRUE;
	}
	if(!strcmp(mov,"0-0")&&valid%2)/*Compare move and Castling Flag '3' Only King side*/
	{
		if(checkstrt(8,typ,5,typ)==FALSE)/*Check Path Clear*/
			return FALSE;
		for(x=5;x<8;x++)
			if(threatpos(x,typ,colr)%16)/*Check Intermediate Positions of King not threatened*/
				return FALSE;
		for(x=0;x<5;x++)/*Castling King Side*/
			change[x]=0;
		return TRUE;
	}
	return FALSE;
}
/*Validate Majors' Move (Gets piece to be moved)*/
vld majpos(const char *mov,const int colr,int *change)
{
	int xpos,ypos,xory=0,temp=1,dbl=0,tmp=0,flg=0,brd,yp=0,xp,ch;
	PLAYER *ply;
	PIECE *tp;
	if(isalpha(mov[2]))/*Third letter also an Alphabet*/
	{
		xp=mov[1];/*(Temporary use of variable)*/
		if(xp>='a'&&xp<='h'||xp>='A'&&xp<='H')/*Valid Identification Alphabet*/
		{
			ch=xposition(xp);/*Find x value given in Move*/
			xory=1;/*flag*/
			temp++;/*x position at next letter*/
		}
		else if(isdigit(xp))/*Valid Identification Number*/
		{
			ch=yposition(xp);/*Find y value given in Move*/
			xory=2;/*flag*/
			temp++;/*x position at next letter*/
		}
		else if(!(xp=='x'||xp=='X'))/*Second Letter not Valid*/
			return FALSE;
	}
	xp=mov[temp];/*Letter at x position of move*/
	if(xp=='x'||xp=='X')/*Kill Sign*/
	{
		temp++;/*Check Next Letter*/
		yp=1;/*Temporary Flag for Kill Move*/
	}
	if(mov[temp+2])/*String Longer than expected*/
		return FALSE;
	ypos=yposition(mov[temp+1]);/*New y Position of Piece*/
	xpos=xposition(mov[temp]);/*New x Position of Piece*/
	brd=bord[xpos][ypos].colour;
	if(!xpos||!ypos||brd==colr)/*Invalid Move*/
		return FALSE;
	if(yp&&!brd)/*Invalid Kill Move*/
		return FALSE;
	ply=play[colr-1];
	for(temp=1;temp<16;temp++)/*Cycle through the pieces*/
	{
		tp=ply->pieces[temp];
		if(tp->name!=mov[0])/*Check Piece Name*/
			continue;/*Incorrect Piece*/
		if(validmov(tp,xpos,ypos,colr)==FALSE)
			continue;
		yp=tp->posy;/*Old y Position of Piece*/
		xp=tp->posx;/*Old x Position of Piece*/
		if(xory)/*Piece Position Supplied in Move*/
			if(xory==1)/*True if x Position Given*/
			{
				if(flg++)/*For Piece Position in Move if both pieces have valid moves*/
					tmp=ch;
				if(xp!=ch)/*Incorrect Piece*/
					continue;
			}
			else/*True if y Position Given*/
			{
				if(flg++)/*For Piece Position in Move if both pieces have valid moves*/
					tmp=ch+('1'-'a');/*Correct for */
				if(yp!=ch)/*Incorrect Piece*/
					continue;
			}
		dbl++;/*No of Move for same position*/
		change[3]=temp;/*Piece Number*/
	}
	if(dbl!=1)/*Not a Single Valid Move(Multiple or No moves)*/
		return FALSE;
	change[0]=brd;/*Opposite piece killed or not*/
	change[1]=xpos;/*New x position*/
	change[2]=ypos;/*New y position*/
	change[4]=tmp;/*Position necessary in the move*/
	return TRUE;
}
/*Validate Pawn Move*/
vld pawnpos(const char *mov,const int colr,int *change)
{
	int xpos,ypos,tmp=0,brd,ch,xp;
	PLAYER *ply;
	PIECE *tp;
	ch=xposition(mov[0]);/*x Position of First Letter*/
	if(!ch)/*Invalid Position*/
		return FALSE;
	switch(mov[1])/*Check Next Letter*/
	{
		case'x': case'X':/*Kill sign then check from next letter*/
			tmp++;/*Fall through to next case*/
		case 'a': case 'A': case 'h': case 'H': case 'b': case 'B': case 'c':
		case 'C': case 'd': case 'D': case 'e': case 'E': case 'g': case 'G':
		case 'F': case 'f':/*Second letter also alphabet-Kill move*/
			tmp++;/*Letter with x position*/
			xpos=xposition(mov[tmp]);
			if(!xpos)/*Wrong Position*/
				return FALSE;
			xp=change[4]=ch;/*Kill move Position Necessary*/
			break;
		default:
			xpos=ch;/*New position of Pawn in first letter if not a kill move*/
			xp=change[4]=0;/*Not Kill Move Position not Necessary*/
			break;
	}
	if(mov[tmp+2])/*String Longer than expected*/
		return FALSE;
	ypos=yposition(mov[tmp+1]);/*New y Position of Pawn*/
	brd=bord[xpos][ypos].colour;
	if(!ypos||brd==colr)/*Invalid y position or same color on new place*/
		return FALSE;
	if(brd&&!xp)/*Piece at the Board Position and not a kill move*/
		return FALSE;
	if(xp&&!brd)/*Kill Move and No Piece on the Board*/
		if(pnflg==xpos&&ypos==6/colr)/*Pawn en passant Flag is same row and new y correct*/
			brd=3-colr;/*Kill Move*/
		else
			return FALSE;
	ply=play[colr-1];
	for(tmp=8;tmp<16;tmp++)
	{
		tp=ply->pieces[tmp];
		if(tp->name!='p')/*Check Piece*/
			continue;
		if(tp->posx!=ch)/*If x Position not same as old Position*/
			continue;
		if(validmov(tp,xpos,ypos,colr)==FALSE)
			continue;
		change[0]=brd;/*Opposite piece killed or not*/
		change[1]=xpos;/*New x position*/
		change[2]=ypos;/*New y position*/
		change[3]=tmp;/*Piece Number*/
		return TRUE;
	}
	return FALSE;
}
/*Check Straight Moves*/
vld checkstrt(const int xp1,const int yp1,const int xp2,const int yp2)
{
	int diffx,diffy,slope,ct,diff;
	diffx=xp1-xp2;/*Movement in x*/
	diffy=yp1-yp2;/*Movement in y*/
	if(diffx&&diffy)/*If movement in more than one direction*/
		return FALSE;
	if(!diffx&&!diffy)/*No Move*/
		return FALSE;
	diff=diffx?diffx:diffy;/*Non Zero Value*/
	ct=diff>0?1:-1;/*Slope of the Non Zero Move*/
	diffx=diffx?ct:0;/*Reset variables to 1 or 0*/
	diffy=diffy?ct:0;
	for(slope=1;slope<ct*diff;slope++)/*Check for Obstacles in the Route*/
		if(bord[xp2+diffx*slope][yp2+diffy*slope].colour)/*From New to Original Position*/
			return FALSE;
	return TRUE;
}
/*Check Diagnol Moves*/
vld checkdiag(const int xp1,const int yp1,const int xp2,const int yp2)
{
	int diffy,diffx,slopex,slopey,ct;
	diffx=xp1-xp2;/*Movement in x*/
	diffy=yp1-yp2;/*Movement in y*/
	if(!diffx&&!diffy)/*No Move*/
		return FALSE;
	if(!(diffx==diffy||diffx==-diffy))/*Check movements in both directions are equal*/
		return FALSE;
	slopex=(diffx<0)?-1:1;/*Slopes of x and y*/
	slopey=(diffy<0)?-1:1;
	for(ct=diffx*slopex-1;ct>0;ct--)/*Check for Obstacles in the Route*/
		if(bord[xp1-slopex*ct][yp1-slopey*ct].colour)/*From Original to New Position*/
			return FALSE;
	return TRUE;
}
/*Check Knight Move*/
vld checknight(const int xp1,const int yp1,const int xp2,const int yp2)
{
		int xm,ym;
		ym=yp1-yp2;/*Move of Knight in y*/
		xm=xp2-xp1;/*Move of Knight in x*/
		if(ym<0)/*Only Positive Signs*/
			ym*=-1;
		if(xm<0)
			xm*=-1;
		if(xm>ym)/*Make ym = bigger move and xm = smaller move*/
		{
			xm+=ym;
			ym=xm-ym;
			xm-=ym;
		}
		if(ym==2&&xm==1)/**Only a two and a half move is valid*/
			return TRUE;
		return FALSE;
}
/*Get position of x as per mov*/
int xposition(const char mov)
{
	switch(mov)/*Convert Alphabet to Integer*/
	{
		case 'a': case 'b': case 'c': case 'd':
		case 'e': case 'f': case 'g': case 'h':
			return mov-'a'+1;
		case 'A': case 'B': case 'C': case 'D':
		case 'E': case 'F': case 'G': case 'H':
			return mov-'A'+1;
	}
	return NULL;
}
/*Get position of y as per mov*/
int yposition(const char mov)
{
	if(mov>='1'&&mov<='8')/*If mov is between 1 and 8 return as int else NULL*/
		return mov-'0';
	return NULL;
}
/*If move to xpos,ypos is physically possible by piece tmp of colour colr*/
vld possmove(PIECE *tmp,const int xpos, const int ypos,const int colr)
{
	int xp,yp,mvx,mvy,col;
	if(xpos>8||xpos<1||ypos>8||ypos<1)/*Invalid Position*/
		return FALSE;
	xp=tmp->posx;/*x position of Piece*/
	yp=tmp->posy;/*y position of Piece*/
	col=bord[xpos][ypos].colour;/*Colour at New Board Position*/
	if(col==colr)/*Position is Own*/
		return FALSE;
	switch(tmp->name)/*Switch as per Pieces*/
	{
		case 'k':/*King Single Move*/
			mvx=xpos-xp;/*No of Moves in x*/
			mvy=ypos-yp;/*No of Moves in y*/
			if(mvx>1||mvx<-1||mvy>1||mvy<-1)/*x or y moves more than 1*/
				return FALSE;
			return TRUE;
		case 'q':/*Queen Straight and Diagnol Move*/
			if(checkstrt(xpos,ypos,xp,yp)==TRUE||checkdiag(xpos,ypos,xp,yp)==TRUE)
				return TRUE;
			return FALSE;
		case 'r':/*Rook Straight Move*/
			return checkstrt(xpos,ypos,xp,yp);
		case 'b':/*Bishop Diagnol Move*/
			return checkdiag(xpos,ypos,xp,yp);
		case 'n':/*Knight Two and a Half Move*/
			return checknight(xpos,ypos,xp,yp);
		case 'p':/*Pawn*/
			mvx=xpos-xp;/*No of Moves in x*/
			if(mvx<0)/*Convert to Positive*/
				mvx*=-1;
			mvy=ypos-yp;/*No of Moves in y*/
			if(colr!=1)/*Positive Move for Pawn to Opposite Side*/
				mvy*=-1;
			if((col||pnflg==xpos&&ypos==6/colr)&&mvx==1&&mvy==1)/*Kill Move Diagnol and Single*/
				return TRUE;/*(also check for en passant pawn)*/
			if(!(col||mvx))/*Not Kill Move and no x movement*/
				if(mvy==1)/*Single y movement*/
					return TRUE;
				else if(mvy==2&&ypos==3+colr&&!bord[xpos][3*colr].colour)
					return TRUE;/*Double y movement from First File and no Intervention*/
			return FALSE;
		default:/*Piece Killed*/
			return FALSE;
	}
}
/*Find Number of Threats and Value of Minimum Threat to a Piece at xpos,ypos*/
int threatpos(const int xpos, const int ypos,const int colr)
{
	int x,xp,yp,cl,col,mnt=600/*Max Possible Piece Value*/,threat=0;
	PLAYER *temp;
	PIECE *tmp;
	col=3-colr;/*Opposite Colour*/
	temp=play[col-1];/*Opposite Set of Pieces*/
	cl=bord[xpos][ypos].colour;/*Board colour at threatened place*/
	bord[xpos][ypos].colour=colr;/*Change to own Colour*/
	for(x=0;x<16;x++)
	{
		tmp=temp->pieces[x];
		xp=tmp->posx;/*x position of Piece*/
		yp=tmp->posy;/*y position of Piece*/
		if(bord[xp][yp].colour==colr)/*Present Enemy Position is Own ie Enemy Killed*/
			continue;
		if(possmove(tmp,xpos,ypos,col)==TRUE)
		{
			threat++;
			if(mnt>tmp->val)
				mnt=tmp->val;
		}
	}
	bord[xpos][ypos].colour=cl;
	return threat+mnt*16;
}
/*Find Threat to King if xp1,yp1 free and xp2,yp2 covered*/
vld kingshield(const int xp1,const int yp1,const int xp2,const int yp2,const int colr)
{
	int tmp,kposx,kposy;
	vld valid=FALSE;
	PIECE *tp;
	tp=play[colr-1]->pieces[0];
	kposx=tp->posx;/*Position of King*/
	kposy=tp->posy;
	if(kposx==xp1&&kposy==yp1)/*If old coordinates are of the King*/
	{
		kposx=xp2;/*Change King Threat Checking Coordinates*/
		kposy=yp2;/*to the New Positions*/
	}
	bord[xp1][yp1].colour=0;/*Clear Old Board Position*/
	tmp=bord[xp2][yp2].colour;/*New Position Colour*/
	bord[xp2][yp2].colour=colr;/*Fill New Position*/
	if(threatpos(kposx,kposy,colr)%16)/*Find Threat to King*/
		valid=TRUE;
	bord[xp1][yp1].colour=colr;/*Refill Board Position*/
	bord[xp2][yp2].colour=tmp;/*Refill New Postion with Old Colour*/
	return valid;
}
/*Find if a Move by piece tmp to xp,yp is valid*/
vld validmov(PIECE *tmp,const int xp,const int yp,const int colr)
{
	if(possmove(tmp,xp,yp,colr)==TRUE&&kingshield(tmp->posx,tmp->posy,xp,yp,colr)==FALSE)
		return TRUE;
	return FALSE;
}
/*Move the Piece as per the Integer array and colour given*/
void changepos(const int *change,const int colr,const vld flg)
{
	int x,y,tmp1,tmp2,tmp3;
	PIECE *temp;/*Temporary variable for faster proccessing*/
	PLAYER *tp;
	x=change[1];/*New x position*/
	y=change[2];/*New y position*/
	pnflg=0;/*Reset Special Pawn Move Flag*/
	if(!(x||y))/*Both Null hence Castling Move*/
	{
		castlemove(change[4],colr,flg);/*Castle*/
		return;
	}
	tmp1=change[3];/*Piece Number*/
	tmp3=colr-1;/*Pieces Colour 0 for White and 1 for Black*/
	tp=play[tmp3];/*Own Player*/
	temp=tp->pieces[tmp1];/*Piece to Change*/
	tmp2=tp->kingflag;/*Castling Flag*/
	if(temp->name=='p')/*Pawn*/
	{
		if(y==(tmp3+4)&&temp->posy==(tmp3?7:2))/*Double Move from First File*/
			pnflg=x;/*Set Pawn Special Move Flag to Pawn Row*/
		else if(y==(tmp3?1:8))/*Pawn Reaches Last File*/
			getnewpc(temp,colr,flg);/*Change to New Piece*/
	}
	else if(tmp2)
	{
		if(!tmp1)/*King Move*/
			tmp2=0;
		else if(tmp1==2&&tmp2%3)/*Queen Rook moved First Time Reduce Flag 7 by 4 %3=0*/
			tmp2-=4;
		else if(tmp1==3&&tmp2%2)/*King Rook moved First Time Reduce Flag 7 by 3 %2=0*/
			tmp2-=3;
		tp->kingflag=tmp2;
	}
	tmp2=change[0];/*Opposite colour if a kill move*/
	if(tmp2)/*Kill Move*/
		killmove(x,y,tmp2-1,flg);/*tmp2=1 0 for White,1 for Black*/
	clearplc(temp->posx,temp->posy,flg);/*Clear Old Position*/
	temp->posx=x;/*New Position*/
	temp->posy=y;
	drawpiece(temp,tmp3,flg);/*Draw New Position*/
}
/*Castling Move*/
void castlemove(const int side,const int colr,const vld flg)
{
	int tmp1,tmp2;
	PLAYER *tmp;
	tmp2=colr-1;/*Colour of Player*/
	tmp1=tmp2?8:1;
	tmp=play[tmp2];/*Own Player*/
	if(side)/*Queen Side Castling*/
	{
		tmp->pieces[0]->posx=3;/*King from e to c*/
		tmp->pieces[2]->posx=4;/*Rook from a to d*/
		clearplc(1,tmp1,flg);/*Clear Board Positions*/
		drawpiece(tmp->pieces[2],tmp2,flg);/*Draw the Rook at New Place*/
	}
	else/*King Side Castling*/
	{
		tmp->pieces[0]->posx=7;/*King from e to g*/
		tmp->pieces[3]->posx=6;/*Rook from h to f*/
		clearplc(8,tmp1,flg);/*Clear Board Positions*/
		drawpiece(tmp->pieces[3],tmp2,flg);/*Draw the Rook at New Place*/
	}
	clearplc(5,tmp1,flg);/*Clear Board Positions*/
	drawpiece(tmp->pieces[0],tmp2,flg);/*Draw the King at New Place*/
	tmp->kingflag=6;/*Reset Castling Flag Castling Done*/
	return;
}
/*Kill opposite Piece (of colour given) in Kill Move*/
void killmove(const int xp,const int yp,const int colr,const vld flg)
{
	int tmp1;
	PIECE *temp;
	play[colr]->noofpieces--;/*Reduce No of Pieces*/
	temp=bord[xp][yp].pieces;/*Piece to be Killed*/
	tmp1=yp;
	if(!temp)/*Piece Not Present, ie En Passant Pawn Capture*/
	{
		tmp1=4+colr;
		temp=bord[xp][tmp1].pieces;
	}
	temp->posx=0;/*Reset Position*/
	temp->posy=0;
	temp->name='\0';/*Erase Name*/
	temp->val=0;
	clearplc(xp,tmp1,flg);
}
/*Get the New Piece User Wants if Pawn has reached last file*/
void getnewpc(PIECE *tmp,const int colr,const vld flg)
{
	int fl=0;
	char ch;
	ch=tmp->name='\0';
	if(flg==TRUE)
	{
		sound(880);/*Beep*/
		delay(200);
		nosound();
	}
	gotoxy(1,22);
	printf("Which New Piece ?\n(Q)ueen\tK(n)ight\n(R)ook\t(B)ishop");
	if(clrflg%(colr+1))/*Computer Colour*/
		tmp->name='q';/*Choice is Queen*/
	while(!tmp->name)
		switch(ch)/*Check Correct Piece entered*/
		{
			case 'Q': case 'q':
				tmp->name='q';
				break;
			case 'R': case 'r':
				tmp->name='r';
				break;
			case 'N': case 'n':
				tmp->name='n';
				break;
			case 'B': case 'b':
				tmp->name='b';
				break;
			default:
				ch=getch();
				break;
		}
	tmp->val=baseval(tmp->name);
	for(fl=22;fl<26;fl++)
	{
		gotoxy(1,fl);
		printf("\r\t\t  ");/*Clear Row*/
	}
	pnflg=9;/*For Change in Pawn to New Piece*/
}
/*Base Value of each Piece*/
int baseval(const char nm)
{
	switch(nm)
	{
		case 'k':/*King*/
			return 400;
		case 'q':/*Queen*/
			return 180;
		case 'r':/*Rook*/
			return 100;
		case 'b': case 'n':/*Bishop and Knight*/
			return 60;
	}
	return NULL;
}
/*Make Move String from Integer Array*/
void makemove(char *move,const int *change,const int colr)
{
	char tem,tm;
	int tmp=0;
	if(!(change[1]||change[2]))/*Castling Move*/
	{
		if(change[4])
			strcpy(move,"0-0-0");
		else
			strcpy(move,"0-0");
		return;
	}
	tm=play[colr-1]->pieces[change[3]]->name+('A'-'a');/*Name of piece*/
	if(!(tm=='P'||pnflg==9))/*Pawn Move Do not add Name to move*/
		move[tmp++]=tm;/*Copy tm to move*/
	if(change[4])
	{
		tem=change[4]+'a'-1;/*Correct for Alphabet from integer*/
		move[tmp++]=tem;/*Copy tem to move*/
	}
	if(change[0])/*Kill Move add x sign*/
		move[tmp++]='x';
	tem=change[1]+'a'-1;/*x position*/
	move[tmp++]=tem;/*Copy tem to move*/
	tem=change[2]+'0';/*y postion*/
	move[tmp++]=tem;/*Copy tem to move*/
	if(pnflg==9)/*Pawn Changed to New Piece*/
	{
		pnflg=0;
		move[tmp++]=tm;/*Add Piece Name after the String*/
	}
	if(kingshield(0,0,0,0,3-colr)==TRUE)/*If Opposite King Check*/
		if(movleft(3-colr)==TRUE)/*Move for Opposite side left*/
			move[tmp++]='+';/*Add + Sign*/
		else
			strcpy(move,"MATE");/*Check Mate Flag*/
	else if(movleft(3-colr)==FALSE)/*No Valid Move for Opposite Side*/
		strcpy(move,"LOCK");/*Dead Lock Draw Flag*/
	move[tmp]='\0';
}
/*Valid Move Left*/
vld movleft(const int colr)
{
	int tmp1,tmp2,tmp3;
	PLAYER *ply;
	PIECE *piec;
	ply=play[colr-1];
	for(tmp1=0;tmp1<16;tmp1++)
	{
		piec=ply->pieces[tmp1];
		if(piec->name)/*Piece Exists*/
			for(tmp2=1;tmp2<9;tmp2++)
				for(tmp3=1;tmp3<9;tmp3++)
					if(validmov(piec,tmp2,tmp3,colr)==TRUE)
						return TRUE;
	}
	return FALSE;
}
/*Copy a Player Position*/
PLAYER *copyplyr(PLAYER *plyr)
{
	PLAYER *temp;
	int x;
	temp=(PLAYER*)malloc(sizeof(PLAYER));
	*temp=*plyr;
	for(x=0;x<16;x++)
	{
		temp->pieces[x]=(PIECE*)malloc(sizeof(PIECE));
		*temp->pieces[x]=*plyr->pieces[x];
	}
	return temp;
}
/*Delete a Player Position and Return Memory*/
void delplyr(PLAYER *plyr)
{
	int x;
	for(x=0;x<16;x++)
		free(plyr->pieces[x]);
	free(plyr);
}
/*Restore a Position*/
void restorpos(PLAYER *white,PLAYER *black)
{
	int tmp1,tmp2;
	delplyr(play[0]);
	play[0]=white;
	delplyr(play[1]);
	play[1]=black;
	restorpiec(brdflg);
}
/*Restore the Board*/
void restorpiec(const vld flg)
{
	int tmp1,tmp2;
	PLAYER *temp;
	for(tmp1=1;tmp1<9;tmp1++)
		for(tmp2=1;tmp2<9;tmp2++)
			clearplc(tmp1,tmp2,flg);
	for(tmp1=0;tmp1<2;tmp1++)
	{
		temp=play[tmp1];
		for(tmp2=0;tmp2<16;tmp2++)
			drawpiece(temp->pieces[tmp2],tmp1,flg);
	}
}
/*Evaluate Position of Colour colr*/
int evalpos(const int colr,const vld flg)
{
	int xp,yp,val,tmp1,tmp2,tmp3,frdm,thrn,oval,bval,tval=0,movs[60];
	char nm;
	PLAYER *tp;
	PIECE *tmp;
	BOARD *tm;
	tp=play[colr];
	for(tmp1=0;tmp1<16;tmp1++)/*Evaluate all Pieces*/
	{
		tmp=tp->pieces[tmp1];
		nm=tmp->name;
		if(!nm)/*Piece Already Killed*/
			continue;
		bval=oval=val=tmp->val;/*Base Value of Piece*/
		frdm=vldmovs(tmp,movs,colr);/*Freedom of the Piece*/
		thrn=0;/*Positions Threatened*/
		for(tmp2=0;tmp2<frdm;tmp2++)
		{
			tm=bord[movs[tmp2*2]]+movs[tmp2*2+1];/*Pointer to Board Position*/
			if(tm->colour==2-colr)
			{
				thrn++;/*Increase Position Threatened*/
				tmp3=tm->pieces->val;
				if(oval<tmp3)/*Highest Piece Threatened if more than Base Value*/
					oval=tmp3;
			}
		}
		val+=(oval-bval)/8;/*Increase Value if Threatening Higher Piece*/
		val+=(frdm+thrn)*2;/*Increase value for degree of freedom and each piece threatened*/
		xp=tmp->posx;
		yp=tmp->posy;
		switch(nm)
		{
			case 'k':/*King*/
				if(tp->kingflag==6)/*Castling Done*/
				{
					val+=10;/*Benefit of Castling*/
					val-=frdm*2;/*Inadequate Protection*/
				}
				if(yp!=(colr?8:1))
					val-=5;/*Danger On Other Files*/
				break;
			case 'p':/*Pawns  and Fall Through to Next Case*/
				if(yp==(colr?2:7))
					val+=20;/*On Second Last File Passed Pawn*/
				else
					val+=(colr?7-yp:yp-2)*2;/*Each Level Advance From First File*/
				if(xp>4)/*Extra Value for Central Pawns*/
					val+=(8-xp)/2;
				else
					val+=(xp-1)/2;
			default:/*Other Pieces*/
				if(flg==TRUE)/*Test for Threats*/
				{
					tmp2=threatpos(xp,yp,colr+1);/*Threat to the Piece*/
					thrn=tmp2%16;/*No of Threats*/
					if(thrn)
					{
						tmp2/=16;/*Minimum value of Killing Piece*/
						tmp3=threatpos(xp,yp,2-colr);/*Protection to the Piece*/
						frdm=tmp3%16;/*No of Protection*/
						if(!frdm)/*No Protection*/
							val=0;
						else if(tmp2<bval)/*Threatening Piece Less than Own*/
							val-=(bval-tmp2);
						else if(frdm<thrn)/*Protection Less Than Threat*/
							val-=tmp3/16;/*Reduce Value by Minimum Value Protecting Piece*/
					}
				}
				break;
		}
		tval+=val;/*Add to Total Value*/
	}
	return tval;
}
/*Check Best Move and Return Change in Position*/
int chkbst(const int lvl,const int colr,const int *change)
{
	int oppch[5],npos;
	PLAYER *white,*black;
	white=copyplyr(play[0]);/*Copy Player Positions*/
	black=copyplyr(play[1]);
	changepos(change,colr+1,brdflg);/*Make the Move*/
	if(lvl)/*Level of Recursion*/
	{
		bestmov(1-colr,lvl-1,oppch);/*Best Move of Opposite Colour*/
		changepos(oppch,2-colr,brdflg);/*Make the Move*/
		npos=bestmov(colr,lvl-1,oppch);/*Best Move of Same Colour*/
	}
	else
		npos=evalpos(colr,TRUE)-evalpos(1-colr,FALSE);/*New Position Do not Check for Threats to Opposite Colour*/
	restorpos(white,black);
	return npos;
}
/*Calculate Best Move*/
int bestmov(const int colr,const int lvl,int *move)
{
	int xp,yp,tmp1,tmp2,tmp3,tmp4,npos,opos=-2000,movs[60],change[5];
	PIECE *temp1,*temp2;
	if(validcastle("0-0",colr+1,change)==TRUE)
	{
		npos=chkbst(lvl,colr,change);
		opos=npos;
		for(tmp4=0;tmp4<5;tmp4++)
			move[tmp4]=change[tmp4];
	}
	if(validcastle("0-0-0",colr+1,change)==TRUE)
	{
		npos=chkbst(lvl,colr,change);
		if(npos>opos)
		{
			opos=npos;
			for(tmp4=0;tmp4<5;tmp4++)
				move[tmp4]=change[tmp4];
		}
	}
	for(tmp1=0;tmp1<16;tmp1++)
	{
		temp1=play[colr]->pieces[tmp1];/*Piece to Be Moved*/
		change[3]=tmp1;/*Piece Number*/
		change[4]=0;/*Position not necessary in the move at this point*/
		tmp2=vldmovs(temp1,movs,colr);/*Freedom of Movement*/
		for(tmp3=0;tmp3<tmp2;tmp3++)
		{
			xp=movs[tmp3*2];
			yp=movs[tmp3*2+1];
			change[0]=bord[xp][yp].colour;/*Opposite piece killed or not*/
			change[1]=xp;/*New position*/
			change[2]=yp;
			npos=chkbst(lvl,colr,change);
			if(npos>opos)
			{
				opos=npos;
				for(tmp4=0;tmp4<5;tmp4++)
					move[tmp4]=change[tmp4];
			}
		}
	}
	temp2=play[colr]->pieces[move[3]];/*Best Move Piece*/
	if(temp2->name=='p'&&move[0])/*Pawn Kill Move*/
		move[4]=temp2->posx;/*Piece Flag is x Position*/
	else
		for(tmp1=0;tmp1<16;tmp1++)/*Check Move by Same Name Piece*/
		{
			temp1=play[colr]->pieces[tmp1];/*Piece to Be Checked*/
			if(temp1==temp2||temp1->name!=temp2->name)
				continue;/*Check Same Name Piece Only*/
			if(validmov(temp1,move[1],move[2],colr+1)==TRUE)/*Piece Moving to Same Location*/
				if(temp1->posx==temp2->posx)/*Same x Position*/
					move[4]=temp2->posy+('1'-'a');/*Piece Flag is y Position*/
				else
					move[4]=temp2->posx;/*Piece Flag is x Position*/
		}
	return opos;
}
/*Returns the number of valid moves of a piece and their coordinates in an array*/
int vldmovs(PIECE *piec,int *pos,const int colr)
{
	int ms=0;
	switch(piec->name)
	{
		case 'k':
			return kingvld(piec,pos,colr);
		case 'q':
			ms=rookvld(piec,pos,colr);
			ms+=bishopvld(piec,pos+ms*2,colr);
			return ms;
		case 'r':
			return rookvld(piec,pos,colr);
		case 'b':
			return bishopvld(piec,pos,colr);
		case 'n':
			return knightvld(piec,pos,colr);
		case 'p':
			return pawnvld(piec,pos,colr);
		default:
			return NULL;
	}
}
/*King Possible Moves*/
int kingvld(PIECE *piec,int *pos,const int colr)
{
	int x,y,xp,yp,frdm=0,posn=0;
	xp=piec->posx;
	yp=piec->posy;
	for(x=xp-1;x<xp+2;x++)/*Find Degrees of Freedom*/
		for(y=yp-1;y<yp+2;y++)
			if(validmov(piec,x,y,colr+1)==TRUE)
			{
				frdm++;/*Increase degrees of Freedom*/
				pos[posn++]=x;/*Return Positions of x and y in Array form*/
				pos[posn++]=y;
			}
	return frdm;
}
/*Rook Possible Moves*/
int rookvld(PIECE *piec, int *pos,const int colr)
{
	int x,y,z,xm,ym,xp,yp,mul,frdm=0,posn=0;
	xp=piec->posx;
	yp=piec->posy;
	for(xm=-1;xm<2;xm++)/*Multitplication factors for x -1,0,1*/
	{
		mul=xm>0?1-xm:1+xm;/*Absolute Multiplication for y is 1 - absolute xm*/
		for(ym=-mul;ym<=mul;ym+=2)/*Mult Factor for y -1 and 1, or 0*/
			for(z=1;z<8;z++)/*Max possible moves in any direction*/
			{
				x=xp+xm*z;/*New x and y positions*/
				y=yp+ym*z;
				if(x<1||x>9||y<1||y>9)/*Position outside board*/
					break;
				if(checkstrt(x,y,xp,yp)==FALSE)/*Straight Move Interrupted*/
					break;
				if(validmov(piec,x,y,colr+1)==TRUE)
				{
					frdm++;/*Increase degrees of Freedom*/
					pos[posn++]=x;/*Return Positions of x and y in Array form*/
					pos[posn++]=y;
				}
			}
	}
	return frdm;
}
/*Bishop Possible Moves*/
int bishopvld(PIECE *piec, int *pos,const int colr)
{
	int x,y,xm,ym,xp,yp,mul,frdm=0,posn=0;
	xp=piec->posx;
	yp=piec->posy;
	for(xm=-1;xm<2;xm+=2)/*Multitplication factors for x and y -1,1*/
		for(ym=-1;ym<2;ym+=2)
			for(mul=1;mul<8;mul++)/*Max possible moves in any direction*/
			{
				x=xp+xm*mul;/*New x and y positions*/
				y=yp+ym*mul;
				if(x<1||x>9||y<1||y>9)/*Position outside board*/
					break;
				if(checkdiag(x,y,xp,yp)==FALSE)/*Diagonal Move Interrupted*/
					break;
				if(validmov(piec,x,y,colr+1)==TRUE)
				{
					frdm++;/*Increase degrees of Freedom*/
					pos[posn++]=x;/*Return Positions of x and y in Array form*/
					pos[posn++]=y;
				}
			}
	return frdm;
}
/*Knight Possible Moves*/
int knightvld(PIECE *piec,int *pos,const int colr)
{
	int x,y,z,xp,yp,frdm=0,posn=0;
	xp=piec->posx;
	yp=piec->posy;
	for(x=-2;x<3;x++)/*Max Possible x movement -2,-1,1,2*/
	{
		if(!x)/*No x move*/
			continue;
		y=x>0?3-x:3+x;/*absolute y move is 3 - absolute x move*/
		for(z=-1;z<2;z+=2)/*+1 and -1*/
			if(validmov(piec,xp+x,yp+y*z,colr+1)==TRUE)
			{
				frdm++;/*Increase degrees of Freedom*/
				pos[posn++]=xp+x;/*Return Positions of x and y in Array form*/
				pos[posn++]=yp+y*z;
			}
	}
	return frdm;
}
/*Pawn Possible Moves*/
int pawnvld(PIECE *piec,int *pos,const int colr)
{
	int x,y,z,xp,yp,mul,frdm=0,posn=0;
	xp=piec->posx;
	yp=piec->posy;
	mul=colr?-1:1;
	for(y=1;y<3;y++)/*Possible y movement 1,2*/
	{
		z=2-y;/*absolute x move is 2 - y move*/
		for(x=-z;x<=z;x++)/*+1,0 and -1*/
			if(validmov(piec,xp+x,yp+y*mul,colr+1)==TRUE)
			{
				frdm++;/*Increase degrees of Freedom*/
				pos[posn++]=xp+x;/*Return Positions of x and y in Array form*/
				pos[posn++]=yp+y*mul;
			}
	}
	return frdm;
}
