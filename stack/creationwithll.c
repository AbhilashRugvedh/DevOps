#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];


void create();
void display();


void main()
{
	for(int i=1;i<=N;i++)
	{
		create();
		
	}
	display();
}

struct node
{
	int data;
	struct node *next;
}*head,*temp,*newnode,*top=0;


void create()
{
	int x;
	printf("Enter Data For Stack :");
	scanf("%d",&x);
	
	newnode=malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
		
}

void display()
{
	temp=top;
	if(top==NULL)
	{
		printf("Stack Is Empty :");
	}
	else
	{
		while(temp!=0)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}

