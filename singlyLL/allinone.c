#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*temp,*head,*newnode,*temp1;;

void create();
void insertatbeg();
void insertatend();
void insertatpos();
void delatbeg();
void delatend();
void delatpos();
void display();

int main()
{
	create();
	printf("Original List Is :");
	display();
	printf("\n");
	insertatbeg();
	printf("List After Insertion at Begining Is :");
	display();
	printf("\n");
	insertatend();
	printf("List After Insertion at End Is :");
	display();
	printf("\n");
	insertatpos();
	printf("List After Insertion at Given Position Is :");
	display();
	printf("\n");
	delatbeg();
	printf("List After Deleted at Beginning Is :");
	display();
	printf("\n");
	delatend();
	printf("List After Deleted at Ending Is :");
	display();
	printf("\n");
	delatpos();
	printf("List After Deleted at Given Position is  :");
	display();
	
}

void create()
{
	int n,i;
	printf("Enetr The Size Of The Linked List :");
	scanf("%d",&n);
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
}

void insertatbeg()
{
	struct node *insertatbeg;
	insertatbeg=malloc(sizeof(struct node));
	printf("Enetr Data For Insert At Begining :");
	scanf("%d",&insertatbeg->data);
	insertatbeg->next=NULL;
	
	temp=head;
	head=insertatbeg;
	insertatbeg->next=temp;
}

void insertatend()
{
	struct node *insertatend=malloc(sizeof(struct node));
	printf("Enetr Data For Insert At End :");
	scanf("%d",&insertatend->data);
	insertatend->next=NULL;
	
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=insertatend;
}

void insertatpos()
{
	int pos,i=1;
	printf("Enter Position to Insert Data :");
	scanf("%d",&pos);
	
	struct node *insertatpos=malloc(sizeof(struct node));
	printf("Enetr Data to Insert at Given Position :");
	scanf("%d",&insertatpos->data);
	
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	
	insertatpos->next=temp->next;
	temp->next=insertatpos;
}

void delatbeg()
{
	temp=head;
	head=temp->next;
	free(temp);
}

void delatend()
{
	temp1=head;
	while(temp1->next!=NULL)
	{
		temp=temp1;
		temp1=temp1->next;
	}
	temp->next=NULL;
	free(temp1);
}

void delatpos()
{
	int i=1,pos;
	printf("Enetr Position To Delete The Element :");
	scanf("%d",&pos);
	
	temp=head;
	while(i<pos)
	{
		temp1=temp;
		temp=temp->next;
		i++;
	}
	temp1->next=temp->next;
}



void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}
