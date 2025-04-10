#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void main()
{
		int n,i,count=0;
		printf("Enter Size of linked List :");
		scanf("%d",&n);
		struct node *head,*temp,*newnode;
		head=(struct node *)malloc(sizeof(struct node));
		printf("Enter Data For Node 1 :");
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
		int k=1;
		while(temp!=NULL)
		{
			printf("%d element in list Is :%d\n",k,temp->data);
			temp=temp->next;
			k++;
			count++;
		}
		printf("Count =%d",count);
}
