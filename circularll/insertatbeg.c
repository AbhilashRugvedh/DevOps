#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*temp,*head,*newnode,*tail,*temp1,*insert;

void create();
void insertatbeg();
void display();

void main()
{
	create();
	printf("Original List Is : ");
	display();
	printf("\n");
	insertatbeg();
	printf("After Insertion :  ");
	display();
	
}

void create()
{
	int n,i;
	printf("Enter Size Of Linked List :");
	scanf("%d",&n);
	
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data For Node 1 :");
	scanf("%d",&head->data);
	
	
	head->next=head;
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		temp->next=newnode;
		tail=newnode;
		tail->next=head;
		temp=temp->next;
	}
}


void insertatbeg()
{
	insert=(struct node *)malloc(sizeof(struct node));
	printf("Enter The Data To Insert :");
	scanf("%d",&insert->data);
	
	temp=head;
	head=insert;
	insert->next=temp;
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
	printf("%d",temp->data);
}

