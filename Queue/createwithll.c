#include<stdio.h>
#include<stdlib.h>

void create();
void display();

struct node
{
	int data;
	struct node *next;
}*rear=0,*front=0,*newnode,*temp,*head;


void main()
{
	int n;
	printf("Enter N Value :");
	scanf("%d\t",&n);
	
	for(int i=1;i<5;i++)
	{
		create();
	}
	display();

}

void create(int x)
{
	for(int i=1;i<=5;i++)
	{
		printf("Enter Data :");
		
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=x;
		//printf("Enter Data :");
		
		newnode->next=0;
	}	
	if(front==0 && rear==0)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}

void display()
{
	if(front==0 && rear==0)
	{
		printf("Queue Is Empty :");
	}
	
	else
	{
		temp=front;
		while(temp!=0)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
		
