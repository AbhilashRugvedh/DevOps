#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *temp,*newnode,*head;
	head=0;
	int choice=1,count=0;
	while(choice)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data :");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		printf("Do You Want To Continue :");
		scanf("%d",&choice);
	}
	temp=head;
	while(temp!=0)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
		count++;
	}
	printf("\n");
	printf("Length Of The Linked List Is %d:",count);
}

