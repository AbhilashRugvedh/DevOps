#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
}*temp,*head,*newnode,*temp1,*tail;

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
	printf("Enter Size Of The Circular Linked List :");
	scanf("%d",&n);
	
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enetr Data for Node 1 :");
	scanf("%d",&head->data);
	temp=head;
	temp->next=head;
	
	//temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		temp->next=newnode;
		newnode->next=head;
		tail=newnode;
		temp=temp->next;
	}
}

void insertatbeg()
{
	struct node *insertatbeg=(struct node*)malloc(sizeof(struct node));
	printf ("Enetr Data to Insert at Beginning :");
	scanf("%d",&insertatbeg->data);
	
	temp=head;
	head=insertatbeg;
	insertatbeg->next=temp;
	tail->next=head;
}

void insertatend()
{
	struct node *insertatend=(struct node*)malloc(sizeof(struct node));
	printf ("Enetr Data to Insert at End :");
	scanf("%d",&insertatend->data);
	
	tail->next=insertatend;
	insertatend->next=head;
	tail=insertatend;
}

void insertatpos()
{
	int i,pos;
	printf("Enter Position to Insert the Data :");
	scanf("%d",&pos);
	
	struct node *insertatpos=(struct node*)malloc(sizeof(struct node));
	printf ("Enetr Data to Insert at Given Position :");
	scanf("%d",&insertatpos->data);
	
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	insertatpos->next=temp->next;
	temp->next=insertatpos;

}

void delatbeg()
{
	temp=head;
	head=temp->next;
	tail->next=head;
}

void delatend()
{
	temp=head;
	while(temp->next!=head)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=head;
	temp1=tail;
}

void delatpos()
{
	int i,pos;
	printf("Enter Position to Delete Element at Given Position :");
	scanf("%d",&pos);
	
	temp=head;
	for(i=1;i<pos;i++)
	{
		temp1=temp;
		temp=temp->next;
	}
	
	temp1->next=temp->next;
	temp->next=NULL;
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



