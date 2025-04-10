#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
} *head,*temp,*newnode,*tail,*insert;

void create();
void insertatend();
void display();

void main()
{
	create();
	printf("Original List Is : ");
	display();
	printf("\n");
	insertatend();
	printf("List After Insertion Is :  ");
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

void insertatend()
{
	insert=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data To Insert at End :");
	scanf("%d",&insert->data);
	
	tail->next=insert;
	insert->prev=tail;
	tail=insert;
	tail->next=head;
	
	
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
