#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*newnode,*head,*temp,*temp1,*tail;

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
	printf("Original Linked List is :");
	display();
	printf("\n");
	insertatbeg();
	printf(" Linked List After Insertion at Beginning is :");
	display();
	printf("\n");
	insertatend();
	printf(" Linked List After Insertion at Ending is :");
	display();
	printf("\n");
	insertatpos();
	printf(" Linked List After Insertion at Position is :");
	display();
	printf("\n");
	delatbeg();
	printf(" Linked List After Deletion at Begining  is :");
	display();
	printf("\n");
	delatend();
	printf(" Linked List After Deletion at Ending  is :");
	display();
	printf("\n");
	delatpos();
	printf(" Linked List After Deletion at given Position  is :");
	display();
}
void create()
{
	int i,n;
	printf("Enter Size Of The Doubly Linked List :");
	scanf("%d",&n);
	
	head=malloc(sizeof(struct node));
	printf("Enter Data for Node 1 :");
	scanf("%d",&head->data);
	head->next=0;
	head->prev=0;
	
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("Enter Data For Node %d :",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		
		temp->next=newnode;
		newnode->prev=temp;
		tail=newnode;
		temp=temp->next;
		tail->next=head;
	}
}

void insertatbeg()
{	
	struct node *insertatbeg=malloc(sizeof(struct node));
	printf("Enter Data To Insert At Beginning :");
	scanf("%d",&insertatbeg->data);
	
	insertatbeg->prev=NULL;
	insertatbeg->next=NULL;
	
	temp=head;
	head=insertatbeg;
	insertatbeg->next=temp;
	temp->prev=insertatbeg;
	tail->next=head;
}

void insertatend()
{
	struct node *insertatend=malloc(sizeof(struct node));
	printf("Enter data To Insert at End :");
	scanf("%d",&insertatend->data);
	
	insertatend->prev=NULL;
	insertatend->next=NULL;
	
	tail->next=insertatend;
	insertatend->prev=tail;
	tail=insertatend;
	tail->next=head;
}

/*

void insertatend()
{
	struct node *insertatend=malloc(sizeof(struct node));
	printf("Enter data To Insert at End :");
	scanf("%d",&insertatend->data);
	
	insertatend->prev=NULL;
	insertatend->next=NULL;
	
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	
	temp->next=insertatend;
	insertatend->prev=temp;
	tail=insertatend;
	tail->next=head;
}
*/

void insertatpos()
{
	int i=1,pos;
	printf("Enter Position To Insert At Given Position :");
	scanf("%d",&pos);
	struct node *insertatpos=malloc(sizeof(struct node));
	printf("Enter Data For Insert at Position :");
	scanf("%d",&insertatpos->data);
	
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	
	temp1=temp->next;
	temp1->prev=insertatpos;
	insertatpos->next=temp1;
	temp->next=insertatpos;
	insertatpos->prev=temp;
}

void delatbeg()
{
	temp=head;
	head=temp->next;
	temp->next=NULL;
	head->prev=NULL;
	tail->next=head;
	free(temp);
	
}

void delatend()
{
	temp1=tail;
	tail=temp1->prev;
	tail->next=head;
	temp1->prev=NULL;
}

void delatpos()
{
	int i=1,pos;
	printf("Enter Position To Delete The Data :");
	scanf("%d",&pos);
	
	temp=head;
	while(i<pos)
	{
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}

void display()
{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("%d  ",temp->data);
}

