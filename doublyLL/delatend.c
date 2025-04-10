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
	
	printf("Deletion At Ending :\n");
	
	temp=head;
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
	
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}


