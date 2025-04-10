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
	printf("Enetr Linked List Size :");
	scanf("%d",&n);
	struct node *head,*newnode,*temp,*insert,*temp1;
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 :");
	scanf("%d",&head->data);
	head->next=NULL;
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
	}
	temp=head;
	printf(" Original List Is :");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
	printf("Insertion At Beginning :\n");
	
	insert=(struct node *)malloc(sizeof(struct node));
	printf("Enetr Element To Insert at Beginning :");
	scanf("%d",&insert->data);
	
	insert->next=head;
	head=insert;
	temp=head;
	printf("List After Insertion Element At Beginning Is :\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}	
}
