#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 1024
typedef struct
{
	int data[MAXSIZE];
	int top;
}SeqStack;
int Push_SeqStack(SeqStack *s, int x);
SeqStack* Init_SeqStack();
int Empty_SeqStack(SeqStack*s);
int Pop_SeqStack(SeqStack*s, int x);
int main()
{
	//clock_t start, end;
	//start = clock();
	SeqStack*s = Init_SeqStack();
	int x=0;
	int n[] = { 1, 2, 3, 4, 5, };
	for (int i=0; i < 5; i++)
	{
		s=Push_SeqStack(s, n[i]);
		printf("%d ", s->data[s->top]);
	}
	while(Empty_SeqStack(s))
	{
		printf("%d ", Pop_SeqStack(s, x));
	}
	//end = clock();
	//printf("%.3f", 1.0*(end - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
int Push_SeqStack(SeqStack *s, int x)
{
	if (s->top==MAXSIZE-1)
	{
		return 0;
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
		return s;
	}
}
SeqStack* Init_SeqStack()
{
	SeqStack*s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}
int Pop_SeqStack(SeqStack*s, int x)
{
		x = s->data[s->top];
		if (!Empty_SeqStack(s))
			return 0;
		s->top--;
		return x;
}
int Empty_SeqStack(SeqStack*s)
{
	if (s->top == -1)return 0;
	else return 1;
}