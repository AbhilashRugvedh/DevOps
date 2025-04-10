#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *prev;
	struct node *next;
} *head,*temp,*new,*temp1,*insert;

void create();
void display();
void insertatbeg();
int main()
{
	create();
	printf("Original List :");
	display();
	insertatbeg();
	printf("List After INsertion At Beginning :");
	display();
}

void create()
{
	int i,n;
	printf("Enter Size Of The List :");
	scanf("%d",&n);
	head=malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 :");
	scanf("%d",&head->data);
	
	head->prev=NULL;
	head->next=NULL;
	
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		new=malloc(sizeof(struct node));
		printf("Enter Data For Node %d :",i);
		scanf("%d",&new->data);
		
		temp->next=new;
		new->prev=temp;
		temp=new;
		
	}
}
void insertatbeg()
{
	insert=malloc(sizeof(struct node));
	printf("Enetr Element To Insert At Beginning :");
	scanf("%d",&insert->data);
	
	temp=head;
	
	insert->next=temp;
	insert->prev=NULL;
	head=insert;	
	printf("\n");
	
}

void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
