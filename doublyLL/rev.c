#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *prev;
	struct node *next;
} *head,*temp,*new,*temp1,*insert,*tail;

void create();
void display();
void rev();
int main()
{
	create();
	printf("Original List :");
	display();
	printf("\n");
	rev();
	printf("reverse Is :");
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
		tail=new;
		temp=new;
	}
}

void rev()
{
	temp=head;
	while(temp!=NULL)
	{
		temp1=temp->next;
		temp->next=temp->prev;
		temp->prev=temp1;
		temp=temp1;
	}
	temp=head;
	head=tail;
	tail=temp;
	
}


void display()
{
	temp=head;
	while(temp!=tail)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("%d  ",temp->data);
}
