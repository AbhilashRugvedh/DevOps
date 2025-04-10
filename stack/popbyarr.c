#include<stdio.h>

#define n 5

int stack[n];
int top=-1;

void create();
void pop();
void display();

void main()
{
	for(int i=1;i<=n;i++)
	{
		create();
	}
	printf("Original Stsck is :\n");
	display();
	
	pop();
	printf("Stack After Deletion Element Is :\n");
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


void pop()
{
	if(top==-1)
	{
		printf("Stack is UnderFlow / Empty :");
	}
	else
	{
		printf("\n");
		printf("Deleted Item Is %d\n",stack[top]);
		top--;
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
