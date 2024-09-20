//Sort an Array of Numbers by various Methods in Ascending or Descending order
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<time.h>
//Main Program which handles input, output, type and method of sort etc.
void main()
{
	int arr[30000]/*Original Array to hold the integers*/,ct/*counter*/,tp/*type of sort*/,mthd/*method of sort*/,size/*no of integers to sort*/;
	typedef clock_t (SORT)(int[],int,int);/*Define the structure of the Sorting functions which accept the array, its size and method of sort (0 for ascending, 1 for descending)*/
	SORT bubble,selection,insertion,quick,partition,*sort[]={bubble,selection,insertion,quick,partition};/*The Various sorting Algos and array to their pointers*/
	FILE*filein,*fileout,*inout(int);/*The input and output streams and the function to open them*/
	clock_t tm;/*Measure the time*/
	clrscr();/*Clear screen*/
	filein=inout(1);/*Open the input stream*/
	printf("\nEnter Array size (Maximum is 30000) ? ");
	scanf("%d",&size);/*The no of integers to be sorted*/
	(unsigned int)size>30000?size=30000:NULL;/*Maximum no of integers which can be sorted is 30000*/
	printf("\nType of Sort :-\tAscending(default)-0/ Descending-1 : ");
	tp=getche();/*Sort ascending/ descending*/
	tp=!((tp-'1')&&(tp-'d')&&(tp-'D'));/*tp is 1 if user presses 1 or D or d*/
	printf("\n\nMethod of Sort :-\n\t\tBubble-0\n\t\tSelection-1\n\t\tInsertion-2\n\t\tQuick Sort (Recursive)-3\n\t\tPartition Sort (Non-Recursive)(default)-4\n");
	mthd=getch();/*Method of Sort*/
	mthd=mthd=='1'||mthd=='2'||mthd=='3'||mthd=='0'?mthd-'0':4;/*mthd is 0-3 depending on user input or 4 on invalid input*/
	printf("\n%s\n",filein==stdin?"Please Enter the Numbers :-":"Reading the Numbers ...");/*Message on console depending on the input stream*/
	for(ct=0;ct<size;ct++)/*Read the numbers*/
		fscanf(filein,"%d",&arr[ct]);
	tm=(sort[mthd])(arr,size,tp);/*Sort the numbers and get the time taken*/
	fileout=inout(0);/*Get the output stream*/
	printf("\n%s\n",fileout==stdout?"The Sorted Numbers are :-":"Writing the Sorted Numbers ...");/*Message on console depending on the output stream*/
	for(ct=0;ct<size;ct++)/*Output the sorted numbers*/
		fprintf(fileout,"%d\n",arr[ct]);
	printf("\nThe Time taken for %s %s Sort (excluding I/O time) is %fs.",tp?"Descending":"Ascending",mthd?mthd-1?mthd-2?mthd-3?"Partition":"Quick":"Insertion":"Selection":"Bubble",tm/CLK_TCK);/*Output Time Taken*/
	getch();/*Wait for keypress*/
	flushall();/*flush all open i/o streams*/
	filein!=stdin?fclose(filein):NULL;/*Close input stream if not stdin*/
	fileout!=stdout?fclose(fileout):NULL;/*Close output stream if not stdout*/
}
//Bubble Sort Algorithm. Get the largest/ smallest unsorted number to the end of the array in each loop
clock_t bubble(int arr[],int size,int mthd)
{
	int loop/*To control inner loop execution*/,flag/*flag*/,swap(int*,int*)/*swapping function*/;
	clock_t strt=clock();/*start time of the algorithm*/
	while(--size)/*sort till the the last number of the array reducing it to 0, as the last numbers are sorted*/
	{
		flag=0;/*initialize flag to 1*/
		for(loop=0;loop<size;loop++)/*continue loop till the last number of the unsorted portion of the array*/
			if((arr[loop]>arr[loop+1])!=mthd)/*Check whether the current number is larger/ smaller than the next number in the array (depending if mthd is 0 or 1)*/
				flag=swap(&arr[loop],&arr[loop+1]);/*swap the two numbers if not in correct sequence and change the flag value to 0*/
		if(!flag)/*check for change in flag value ie numbers not in sequence*/
			break;/*break from loop if numbers are already sorted*/
	}
	return clock()-strt;/*return the time taken for the sort*/
}
//Selection Sort Algorithm. Find the smallest/ largest unsorted number and get it to next position in the array
clock_t selection(int arr[],int size,int mthd)
{
	int ct1/*counter for outer loop*/,ct2/*counter for inner loop*/,flag/*position of the next number to be sorted*/,swap(int*,int*)/*swapping function*/;
	clock_t strt=clock();/*start time of the algorithm*/
	for(ct1=0;ct1<size;ct1++)/*run the outer loop from the first to the last position in the array*/
	{
		flag=ct1;/*flag initialized to the initial position*/
		for(ct2=ct1+1;ct2<size;ct2++)/*run inner loop from the initial position to the end of the array*/
			if((arr[ct2]<arr[flag])!=mthd)/*find the next smallest/ largest element (depending if mthd is 0 or 1)*/
				flag=ct2;/*flag value changed to position of that element*/
		if(flag>ct1)
			swap(&arr[flag],&arr[ct1]);/*swap the corrrect element with the one in the current position*/
	}
	return clock()-strt;/*return the time taken for the sort*/
}
//Insertion Sort Algorithm. Place each number in its correct position in the array
clock_t insertion(int arr[],int size,int mthd)
{
	int ct1/*counter for outer loop*/,ct2/*counter for inner loop*/,num/*number to place*/;
	clock_t strt=clock();/*start time of the algorithm*/
	for(ct1=1;ct1<size;ct1++)/*run outer loop from second to the last number in the array*/
		if((arr[ct1-1]<arr[ct1])==mthd)/*check if number is in correct position*/
		{
			num=arr[ct1];/*initialize the number to place in its position*/
			for(ct2=ct1-1;ct2>=0;ct2--)/*run inner loop from initial position to first number in the array*/
				if((arr[ct2]<num)==mthd)/*check if previous number is smaller/ larger than num (depending if mthd is 0 or 1)*/
					arr[ct2+1]=arr[ct2];/*shift numbers to the next position*/
				else
					break;/*break if the previous number is in the correct position*/
			arr[ct2+1]=num;/*assign num to the position before the last shift*/
		}
	return clock()-strt;/*return the time taken for the sort*/
}
//Quick Sort Calling Routine
clock_t quick(int arr[],int size,int mthd)
{
	clock_t qsort(int[],int,int,int);/*define the quick sort function which accepts array, first and last position to sort, and the method of sort (1 for ascending, -1 for descending)*/
	return qsort(arr,0,size-1,mthd?-1:1);/*return the time taken by qsort which is initially called with parameters of first and last number in the array*/
}
//Quick Sort Algorithm (Recursive)
clock_t qsort(int arr[],int lt,int rt,int mthd)
{
	int sorts(int [],int,int,int)/*define the sorting function*/,ct/*counter returned by sorting function*/;
	clock_t strt=clock();/*start time of the algorithm*/
	if(!(rt>lt))
		return NULL;/*return NULL if  second position is not more than first position*/
	ct=sorts(arr,lt,rt,mthd);/*sort the array into two parts divided by ct*/
	qsort(arr,lt,ct-1,mthd);/*sort the numbers before ct*/
	qsort(arr,ct+1,rt,mthd);/*sort the numbers after ct*/
	return clock()-strt;/*return the time taken for the sort*/
}
//Heap Structure to Store Partition Sort Boundaries as a Link List
struct heap
{
	int lt;/*left position*/
	int rt;/*right position*/
	struct heap*lst;/*pointer to the next link*/
};
//Partition Sort Algorithm (Non Recursive)
clock_t partition(int arr[],int size,int mthd)
{
	int sorts(int [],int,int,int)/*define the sorting function*/,ct/*counter returned by sorting function*/,lt/*left counter*/,rt/*right counter*/,temp1,temp2/*temporary variables*/;
	clock_t strt=clock();/*start time of the algorithm*/
	struct heap*first=NULL,/*first link in the sorting heap*/*tree/*to navigate the heap*/,*add(struct heap*,int,int)/*to push a link to the heap*/;
	first=add(first,0,size-1);/*add the first sorting positions to the heap*/
	mthd=mthd?-1:1;/*mthd is 1 for ascending (got 0) and -1 for descending (got 1) sort*/
	while(first)/*continue loop till the first link doesn't point to NULL*/
	{
		rt=first->rt;/*right side of the array to sort*/
		lt=first->lt;/*left side of the array to sort*/
		tree=first;/*save first link before deletion*/
		first=first->lst;/*pop from the heap*/
		free((void*)tree);/*free the link*/
		while(rt>lt)/*continue loop till right position is more than left position*/
		{
			ct=sorts(arr,lt,rt,mthd);/*sort array into two parts divided by ct*/
			if(rt-ct>ct-lt)/*if right area of sort is greater then*/
			{
				temp1=lt;/*left margin of addition to heap*/
				temp2=ct-1;/*right margin of addition to heap*/
				lt=ct+1;/*modify the left margin for new sort*/
			}
			else/*if left area of sort is greater then*/
			{
				temp1=ct+1;/*left margin of addition to heap*/
				temp2=rt;/*right margin of addition to heap*/
				rt=ct-1;/*modify the right margin for new sort*/
			}
			if(temp2>temp1)/*if the right margin is more than left margin*/
				first=add(first,temp1,temp2);/*add new link to heap*/
		}
	}
	return clock()-strt;/*return the time taken for the sort*/
}
//Add a Link to the Heap of Partitions to be Sorted
struct heap*/*void*/ add(struct heap*first,int lt,int rt)
{
	struct heap*ad=(struct heap*)malloc(sizeof(struct heap))/*new link for the sorting heap*/;
	ad->lt=lt;/*add the left margin to the link*/
	ad->rt=rt;/*add the right margin to the link*/
	ad->lst=first;/*push up the heap*/
	return ad;/*return the new first link*/
}
//The Common Sorting Procedure in Quick Sort and Partition Sort
int sorts(int arr[],int lt,int rt,int mthd)
{
	int swap(int*,int*)/*swapping function*/,ct1=lt/*first counter initialized to left position*/,ct2=rt/*second counter initialized to right position*/,ct=(lt+rt)/2/*middle position*/;
	if(mthd*arr[lt]>mthd*arr[rt])
		swap(&arr[lt],&arr[rt]);/*get the smaller/ larger number to left position*/
	if(mthd*arr[ct]>mthd*arr[lt])
	{
		swap(&arr[lt],&arr[ct]);/*get the smallest/ largest of the three numbers (lt,rt & middle)*/
		if(mthd*arr[lt]>mthd*arr[rt])/*to middle position, the largest/ smallest to the right position and*/
			swap(&arr[lt],&arr[rt]);/*the middle one to the left position (depending if mthd is 1 or -1)*/
	}
	do
	{
		while(mthd*arr[++ct1]<mthd*arr[lt]);/*increase left pointer to the number greater/ smaller than left number (depending if mthd is 1 or -1)*/
		while(mthd*arr[--ct2]>mthd*arr[lt]);/*decrease right pointer to the number smaller/ greater than left number (depending if mthd is 1 or -1)*/
	}while((ct2>ct1)&&swap(&arr[ct1],&arr[ct2]));/*if right counter>left counter swap the two numbers and continue loop*/
	swap(&arr[lt],&arr[ct2]);/*swap the left number with the number at right counter*/
	return ct2;/*return the position of right counter for further sorting*/
}
//Swap two numbers
int swap(int*num1,int*num2)
{
	int temp=*num1;/*temporary number for swapping*/
	*num1=*num2;/*swap the*/
	*num2=temp;/*numbers*/
	return !NULL;/*return a true value ie 1*/
}
//To Open a File for Input or Output
FILE*inout(int mode)
{
	char file[100]/*the filename to open*/,*type=mode?"Input":"Output"/*for screen message*/;
	FILE*tst=NULL;/*file pointer to open and return*/
	fflush(stdin);/*flush the standard input*/
		printf("\nEnter %s Filename (Maximum Length 100. Standard %s on Blank or Error) :\n",type,type);
	gets(file);/*get the filename to open for input/ output*/
	if(tst=fopen(file,mode?"r":"w"))/*open the file for input/ output and check if it is opened correctly*/
		return tst;/*return the opened file stream*/
	if(*file!='\0')/*check if no filename entered*/
		printf("\nError opening file specified. Using Standard %s\n",type);/*Error message*/
	return mode?stdin:stdout;/*return standard input/output*/
}