#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
} *head,*temp,*newnode,*tail,*temp1;

void create();
void delatpos();
void display();

void main()
{
	create();
	printf("Original List Is : ");
	display();
	printf("\n");
	delatpos();
	display();
}

void create()
{
	int n,i;
	printf("Enetr The Size Of The List :");
	scanf("%d",&n);
	
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 :");
	scanf("%d",&head->data);
	
	temp=head;
	
	head->next=NULL;
	head->prev=NULL;
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		tail=newnode;
		newnode->next=head;
		temp->next=newnode;
		newnode->prev=temp;
		temp=temp->next;
		
	}
}


void delatpos()
{
	int i=1,pos;
	printf("Enter Position To Delete Element :");
	scanf("%d",&pos);
	
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
	}
	
	temp1=temp->next->next;
	temp->next=temp1;
	temp1->prev=temp;
}


























void display()
{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d   ",temp->data);
}	
