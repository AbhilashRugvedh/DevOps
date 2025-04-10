#include<stdio.h>
#define n 5

int queue[n];
int rear=-1,front=-1;

void enqueue();
void dequeue();
void display();

int main()
{
	for(int i=1;i<=n;i++)
	{
		enqueue();
	}
	display();
	printf("\n");
	dequeue();
	display();
}

void enqueue()
{
	int x;
	printf("Enter Data :");
	scanf("%d",&x);
	
	if(rear==-1 && front==-1)
	{
		rear=front=0;
		queue[rear]=x;
	}
	else
	{
		rear=(rear+1)%n;
		queue[rear]=x;
	}
}

void dequeue()
{
	if(rear==-1 && front==-1)
	{
		printf("Queue Is Under flow :");
	}
	else
	{
		front=(front+1)%n;
	}
}

void display()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty ");
	}
	else
	{
		int i=front;
		while(i!=rear)
		{
			printf("%d  ",queue[i]);
			i=(i+1)%n;
		}
		printf("%d  ",queue[i]);
	}
}
