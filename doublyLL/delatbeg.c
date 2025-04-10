#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head,*newnode,*temp,*temp1,*insert;

void main()
{
	int n,i;
	printf("Enetr Size Of Linked List :");
	scanf("%d",&n);
	
	head=malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 :");
	scanf("%d",&head->data);
	
	temp=head;
	temp->next=NULL;
	temp->prev=NULL;
	
	for(i=2;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		newnode->prev=temp;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
		
	}
	
	temp=head;
	int count=0;
	printf("Original Linked List Is :\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
		count++;
	}
	
	temp=head->next;
	head=temp;
	temp->prev=NULL;
	
	printf("Deletion At Beggining :\n");
	
	temp1=head;
	while(temp1!=NULL)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->next;
	}
}


