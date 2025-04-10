#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*temp,*temp1,*head,*newnode,*temp2;

void create();
void rev();
void dis();

int main()
{
	create();
	printf("Orioginal List Is :");
	dis();
	printf("\n");
	rev();
	printf("Reverse Of The List Is :");
	dis();
}

void create()
{
	int n,i;
	printf("Enter Size Of The Linked List :");
	scanf("%d",&n);
	
	head=malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 ");
	scanf("%d",&head->data);
	
	head->next=NULL;
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("Enter Data For Node %d ",i);
		scanf("%d",&newnode->data);
		
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
	}
}

void rev()
{
	temp1=0;
	temp2=0;
	
	while(head!=NULL)
	{
		temp2=head->next;
		head->next=temp1;
		temp1=head;
		head=temp2;
	}
	head=temp1;
}

void dis()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}
