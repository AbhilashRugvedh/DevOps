#include<stdio.h>
#define n 5

int queue[n];
int rear=-1,front=-1;
int count=0;

void enqueue(int x);
void dequeue();
void display();

int main()
{
	int x;
	for(int i=0;i<n;i++)
	{
		enqueue(x);
	}
	display();
	printf("\n");
	dequeue();
	display();
}

void enqueue(int x)
{
	printf("Enter Data To The Queue :");
	scanf("%d",&x);
	
	if(rear==-1 && front==-1)
	{
		rear=front=0;
		queue[rear]=x;
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}

void dequeue()
{
	if(rear==-1 && front==-1)
	{
		printf("Queue Is Empty :");
	}
	else
	{
		int item=queue[front];
		front++;
		printf("deleted item is :%d\n",item);
	}
}

void display()
{
	if(rear==-1 && front==-1)
	{
		printf("Queue Is Empty :");
	}
	else
	{
		int i;
		for(i=front;i<rear+1;i++)
		{
			printf("%d  ",queue[i]);
		}
		
	}
}
