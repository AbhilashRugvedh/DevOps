#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
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
	
	
	int choice;
	
	
	while(1)
	{
		printf("\nEnetr Your Choice \n 1. Insert at Begging.\n 2. Insert at End.\n 3. Insert at Given Position.\n 4. Delete at Beginning.\n 5. Delete at End.\n 6. Delete at Position.\n 7. Display.\n 8. Exit");
	scanf("%d",&choice);


		switch(choice)
		{
			case 1: insertatbeg();
			break;
			case 2: insertatend();
			break;
			case 3: insertatpos();
			break;
			case 4: delatbeg();
			break;
			case 5: delatend();
			break;
			case 6: delatpos();
			break;
			case 7: display();
			printf("\n");
			break;
			case 8: printf("Program Execuated Sucessfully");
			printf("\n");
			return 0;
			
			default: printf("Invalid Choice Entered :");
		}
	}
	return 0;
	
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
