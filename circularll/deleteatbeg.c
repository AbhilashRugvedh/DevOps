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
		struct node *head,*temp,*newnode,*tail,*temp1,*del;
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
		printf("Original List is :");
		while(temp1->next!=head)
		{
			printf("%d\t",temp1->data);
			temp1=temp1->next;
		}
		printf("%d",temp->data);
		
		printf("\n");
		
		del=head->next;
		temp->next=del;
		
		temp1=del;
		printf("List After Deleting First Element is :\n");
		while(temp1->next!=del)
		{
			printf("%d\t",temp1->data);
			temp1=temp1->next;
		}
		printf("%d",temp->data);
		
}
