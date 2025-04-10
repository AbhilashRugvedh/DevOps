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
		count++;
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
	printf("Length Of Linked List =%d",count);
	
	printf("\n");
	
	int pos,j=1;
	printf("Enetr Position :");
	scanf("%d",&pos);
	
	if(pos<0)
	{
		printf("Enetred Position Is Negative  :");
	}
	else if(pos>count)
	{
		printf("Enetred Positon Is Out Of Range :");
	}
	else
	{
		insert=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Element To Insert In a Specific Position :");
		scanf("%d",&insert->data);
		
		temp=head;
		while(j<pos-1)
		{
			temp=temp->next;
			j++;
		}
		
		insert->next=temp->next;
		temp->next=insert;
		
		temp1=head;
		while(temp1!=NULL)
		{
			printf("%d\t",temp1->data);
			temp1=temp1->next;
		}
	}
}
		
		

