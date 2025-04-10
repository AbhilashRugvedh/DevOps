#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void main()
{
	int n,i;
	printf("Enetr Size Of Linked List :");
	scanf("%d",&n);
	
	struct node *head,*newnode,*temp,*temp1,*prev,*current;
	head=malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 :");
	scanf("%d",&head->data);
	
	head->next=NULL;
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
	}
	
	temp1=head;
	printf("Original List Is : ");
	while(temp1!=NULL)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->next;
	}
	
	
	current=newnode=head;
	prev=0;
	
	while(newnode!=NULL)
	{
		newnode=newnode->next;
		current->next=prev;
		prev=current;
		current=newnode;
	}
	
	head=prev;
	temp1=head;
	printf("\n");
	printf("Reverse Of The Linked List Is :");
	while(temp1!=NULL)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->next;
	}
}
		
	
