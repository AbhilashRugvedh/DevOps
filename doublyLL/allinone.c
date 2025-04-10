#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * prev;
	struct node *next;
}*temp,*head,*newnode,*temp1;

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
	printf("List After Insertion at Beginning Is :");
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
	printf("List After Deletion at Beginning Is :");
	display();
	printf("\n");
	delatend();
	printf("List After Deletion at End Is :");
	display();
	printf("\n");
	delatpos();
	printf("List After Deletion at Given Position Is :");
	display();
}


void create()
{
	int n,i;
	printf("Enter Size Of The Doubly Linked List :");
	scanf("%d",&n);
	
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enetr Data for Node 1 :");
	scanf("%d",&head->data);
	head->prev=NULL;
	head->next=NULL;
	
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		newnode->prev=NULL;
		newnode->next=NULL;
		
		temp->next=newnode;
		newnode->prev=temp;
		temp=temp->next;
		
	}
}


void insertatbeg()
{
	struct node *insertatbeg=(struct node *)malloc(sizeof(struct  node));
	printf("Enetr Data to Insert at Beginning :");
	scanf("%d",&insertatbeg->data);
	insertatbeg->prev=0;
	insertatbeg->next=0;
	
	temp=head;
	head=insertatbeg;
	head->next=temp;
}
	
void insertatend()
{
	struct node *insertatend=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data to Insert at End :");
	scanf("%d",&insertatend->data);
	insertatend->prev=0;
	insertatend->next=0;
	
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=insertatend;
	insertatend->prev=temp;
}		


void insertatpos()
{
	int i=1,pos;
	printf("Enetr Position to Insert Data :");
	scanf("%d",&pos);
	
	struct node *insertatpos=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data To Insert At Given Position :");
	scanf("%d",&insertatpos->data);
	insertatpos->prev=NULL;
	insertatpos->next=NULL;
	
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	temp1=temp->next;
	
	temp->next=insertatpos;
	insertatpos->prev=temp;
	insertatpos->next=temp1;
	temp1->prev=insertatpos;
}
	
void delatbeg()
{
	temp=head;
	head=temp->next;
	head->prev=NULL;
	free(temp);
}

void delatend()
{
	temp=head;
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;
	}
	
	temp1->next=NULL;
	temp->prev=NULL;
	
	free(temp);
}

void delatpos()
{
	int i,pos;
	printf("Enetr Position to Delete Data :");
	scanf("%d",&pos);
	
	temp=head;
	for(i=1;i<pos;i++)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=temp->next;
	temp->next->prev=temp1;
	free(temp);
}


void display()
{
	temp=head;
	while(temp->next!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d ",temp->data);
}
