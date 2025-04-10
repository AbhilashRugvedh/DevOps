#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*temp,*head,*newnode,*tail,*temp1;

void create();
void delatpos();
void display();

void main()
{
	create();
	display();
	printf("\n");
	delatpos();
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


void delatpos()
{	
	int i=1,pos;
	printf("Enter position to Delete :");
	scanf("%d",&pos);
	
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
	}
	
	temp1=temp->next;
	temp->next=temp1->next;
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


