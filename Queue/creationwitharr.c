#include<stdio.h>

#define n 5

int queue[n];
int front=-1;
int rear=-1;

void create();
void enque();
void display(); 
void deque();

void main()
{
	
	for(int i=1;i<=n;i++)
	{
		create(i);
	}
	printf("Original Queue is :\n");
	display();
	printf("\n");
	enque();
	printf("Queue After Insert Element :\n");
	display();
	deque();
	deque();
	deque();
	printf("Queue after Delete First Element :\n");
	display();
	
}

void create()
{
	int x;
	printf("Enter Value To Queue :");
	scanf("%d",&x);
	if(rear==n-1)
	{
		printf("Over Flow :");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}

void enque()
{
	int a;
	printf("Enetr New Element To Insert Into the Queue :");
	scanf("%d",&a);
	
	rear++;
	queue[rear]=a;
	
	
}
	

void deque()
{
	printf("\n");
	if(front==-1 && rear==-1)
	{
		printf("Queue Is Under Flow / Empty :");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		printf("Deleted Item Is :%d\n",queue[front]);
		front++;
		
	}
}



void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("Queue is Underflow");
	}
	else
	{
		for(i=front;i<rear+1;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}

