#include<stdio.h>

#define n 5

int stack[n];
int top=-1;

void create();

void display();

void main()
{
	for(int i=1;i<=n;i++)
	{
		create();
	}
	printf("Original Stsck is :\n");
	display();
	
}

void create()
{
	int x;
	printf("Enetr Element Into The Stack :");
	scanf("%d",&x);
	
	if(top==n-1)
	{
		printf("Stack is Overflow / Full :");
	}
	else
	{
		stack[++top]=x;
	}
}


void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}
