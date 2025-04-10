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
		printf("Enter Size of linked List :");
		scanf("%d",&n);
		struct node *head,*temp,*newnode,*tail,*temp1;
		head=(struct node *)malloc(sizeof(struct node));
		printf("Enter Data For Node 1 :");
		scanf("%d",&head->data);
		
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
		
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		tail=temp;
		temp->next=head;
		
		temp1=head;
		printf("Original List Is :\n");
		while(temp1->next!=head)
		{
			printf("%d\t",temp1->data);
			temp1=temp1->next;
		}
		printf("%d",temp->data);
		printf("\n");
		
		printf("List After Deleting Element At End Is :\n");
		
		temp1=head;
		while(temp1->next!=head)
		{
			printf("%d\t",temp1->data);
			temp1=temp1->next;
		}
		
}
