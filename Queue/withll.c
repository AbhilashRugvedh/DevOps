#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*newnode,*temp,*temp;
struct node *rear=0,*front=0;

void enqueue();
void dequeue();
void display();

int main()
{
	int n,i;
	printf("Enter Size Of The Queue :");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
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
	printf("Enter Data To The Queue :");
	scanf("%d",&x);
	newnode=malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=0;
	
	if(rear==0 && front==0)
	{
		rear=front=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}

void dequeue()
{
	temp=front;
	if(front==0 && rear==0)
	{
		printf("Queue Is Empty :");
	}
	else
	{
		printf("deleted =%d\n",temp->data);
		front=front->next;
	}
}

void display()
{
	temp=front;
	if(front==0 && rear==0)
	{
		printf("Queue Is Empty :");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
	}
}
