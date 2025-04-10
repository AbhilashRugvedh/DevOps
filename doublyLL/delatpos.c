#include<stdio.h>
#include<stdlib.h>

void create();
void delatpos();
void display();

struct node
{	
	int data;
	struct node *next;
	struct node *prev;
}*head,*temp,*newnode,*temp1;

void main()
{
	create();
	printf("Original List Is :  ");
	display();
	printf("\n");
	delatpos();
	printf("List After Deletion at Position :");
	display();
}

void create()
{
	int i,n;
	printf("Enetr Size Of The Linked List :");
	scanf("%d",&n);
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enetr data For Node 1 :");
	scanf("%d",&head->data);
	
	head->next=NULL;
	head->prev=NULL;
	
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		newnode->next=NULL;
		newnode->prev=temp;
		temp->next=newnode;
		temp=temp->next;
		
	}
}

		
		
void delatpos()
{
	int i=1,pos;
	printf("Enetr Position To Delete Element :");
	scanf("%d",&pos);
	
	temp=head;
	while(i<pos)
	{
		temp=temp->next;
		i++;
	}
	temp1=temp->prev;
	temp1->next=temp->next;
	temp->next->prev=temp1;
}
		
		
void display()
{
	temp=head;
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}		
		
		
		
		
