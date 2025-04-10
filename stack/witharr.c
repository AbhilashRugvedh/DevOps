#include<stdio.h>
#define n 5

int stack[n];
int top=-1;

void push();
void pop();
void display();

int main()
{
	for(int i=1;i<=n;i++)
	{
		push();
	}
	display();
	printf("\n");
	pop();
	display();
}

void push()
{
	int x;
	printf("Enter Data to Stack :");
	scanf("%d",&x);
	
	if(top==n-1)
	{
		printf("Stack Is Overflow :");
	}
	
	else
	{
		top++;
		stack[top]=x;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("Stack Is UnderFlow :");
	}
	else
	{
		top=top-1;
	}
}

void display()
{
	for(int i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}
