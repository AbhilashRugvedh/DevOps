#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void main()
{
	int n,i;
	printf("Enter Number OF Nodes :");
	scanf("%d",&n);
	
	struct node *head,*temp,*newnode,*temp1;
	
	head=malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 :");
	scanf("%d",&head->data);
	
	head->prev=NULL;
	head->next=NULL;
	
	printf("%d",head->data);
	
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("Enetr data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		temp->next=newnode;
		newnode->prev=temp;
		temp=newnode;
		
	}
	
	temp1=head;
	
	printf("Linked List Is :");
	while(temp1!=NULL)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->next;
	}
	
		
	
	
}
