#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*temp,*temp1,*newnode,*head;

void create();
void insertatbeg();
void insertatpos();
void insertatend();
void delatbeg();
void delatpos();
void delatend();
void display();

int main()
{
	create();
	printf("Original List Is :");
	display();
	printf("\n");
	
	int choice;
	while(1)
	{
		printf("\nMENU\nEnter Your Choice :\n 1. Insert at Begining.\n 2. Insert at Position.\n 3. Insert at End.\n 4. Delete at Begining.\n 5. Delete at Position.\n 6. Delete at End.\n 7. Display.\n 8. Exit\n ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 : insertatbeg();
			break;
			case 2 : insertatpos();
			break;
			case 3 : insertatend();
			break;
			case 4 : delatbeg();
			break;
			case 5 : delatpos();
			break;
			case 6 : delatend();
			break;
			case 7 : display();
			break;
			case 8 : printf("Program Executed Sucessfully :");
			return 0;
			default : printf("Invalid Choice ");
		}
	}
}


void create()
{
	int i,n;
	printf("Enter Size Of The Linked List :");
	scanf("%d",&n);
	head=malloc(sizeof(struct node));
	printf("Enter Data For Node 1 :");
	scanf("%d",&head->data);
	head->prev=NULL;
	head->next=NULL;
	
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=malloc(sizeof(struct node));
		printf("Enter Data For Node %d :",i);
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
	struct node* insertatbeg=malloc(sizeof(struct node));
	printf("Enter Data To Insert at Begining :");
	scanf("%d",&insertatbeg->data);
	insertatbeg->prev=NULL;
	insertatbeg->next=NULL;
	
	temp=head;
	head=insertatbeg;
	head->next=temp;
	temp->prev=head;
}

void insertatpos()
{
	int i=1,pos;
	printf("Enter Position to Insert At Position :");
	scanf("%d",&pos);
	struct node* insertatpos=malloc(sizeof(struct  node));
	printf("Enter Data to Insert At Position :");
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

void insertatend()
{
	struct node* insertatend=malloc(sizeof(struct node));
	printf("Enter data To INsert at end :");
	scanf("%d",&insertatend->data);
	insertatend->prev=NULL;
	insertatend->next=NULL;
	
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=insertatend;
	insertatend->prev=temp;
}

void delatbeg()
{
	temp=head;
	head=temp->next;
	head->prev=NULL;
	temp->next=NULL;
	
	free(temp);
}

void delatpos()
{
	int i=1,pos;
	printf("Enter Position To Delete Data :");
	scanf("%d",&pos);
	
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	temp1=temp->next;
	temp->next=temp1->next;
	temp1->next->prev=temp1->prev;
	
	temp1->prev=NULL;
	temp1->next=NULL;
	free(temp1);
}

void delatend()
{
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp1=temp->prev;
	
	temp1->next=NULL;
	temp->prev=NULL;
	free(temp);
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
	
