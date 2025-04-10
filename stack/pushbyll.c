#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];


void create();
void display();
void push();


void main()
{
	for(int i=1;i<=N;i++)
	{
		create();
		
	}
	display();
	printf("\n");
	
	push();
	printf("After Insertion The Stack Is : ");
	display();
	
}

struct node
{
	int data;
	struct node *next;
}*head,*temp,*newnode,*top=0,*insert;


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

void push()
{
	int k;
	printf("Enetr Data To Insert Into the Stack :");
	scanf("%d",&k);
	insert=malloc(sizeof(struct node));
	insert->data=k;
	insert->next=top;
	
	top=insert;
	temp=top;
	
	
	
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

