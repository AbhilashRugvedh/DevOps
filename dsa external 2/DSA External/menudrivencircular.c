#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*tail,*newnode,*temp;

void create(int n);
void display();
void insertion();
void deletion();
void reverse();

int main()
{
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("Circular linked list before operations:\n");
	display();
	while(1)
	{
		int choice;	
		printf("\n1.To perform insertion\n2.To perform deletion\n3.To reverse the linked list\n4.To EXIT\n");
		printf("Enter your choice to perform the operation:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	insertion();
				printf("Linked list after insertion is:\n");
				display();
				break ;
			case 2:  deletion();
				printf("Linked list after deletion is:\n");
				display();
				break;
			case 3 : reverse();
				printf("Reversed linked list is:\n");
				display();
				break;
			case 4:  printf("PROGRAM ENDED");
				exit(0);
			default : printf("enter correct choice\n");
		}
	}
}

void create(int n)
{
	tail=NULL;
	for(int i=1;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data of node %d :",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(tail==NULL)
		{
			tail=newnode;
			tail->next=newnode;
		}
		else 
		{
			newnode->next=tail->next;
			tail->next=newnode;
			tail=newnode;
		}
	}
}
void display()
{	
	if(tail==NULL)
	{	
		printf("List is empty:\n");
	}
	else 
	{
		temp=tail->next;
		while(temp->next!=tail->next)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d ",temp->data);
	}
}


void insertion()
{
	int choice;
	printf("1.Insert at beginning\n2.Insert at ending\n3.Insert at position\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to insert:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(tail==NULL)
	{
		tail=newnode;
		tail->next=newnode;
	}
	else
	{
		if(choice==1)
		{	
			newnode->next=tail->next;
			tail->next=newnode;
		}
		else if(choice==2)
		{	
			newnode->next=tail->next;
			tail->next=newnode;
			tail=newnode;
		}
		else if(choice==3)
		{	
			int pos;
			printf("Enter the position to insert:");
			scanf("%d",&pos);
			temp=tail->next;
			int length=1;
			while(temp->next!=tail->next)
			{
				temp=temp->next;
				length++;
			}
			if(pos<1 || pos>length)
			{
				printf("Invalid chioce\n");
				
			}
			else if(pos==1)
			{
				
				newnode->next=tail->next;
				tail->next=newnode;
			}
			else 
			{
				int i=1;
				temp=tail->next;
				while(i<pos-1)
				{
					temp=temp->next;
					i++;
				}
				newnode->next=temp->next;
				temp->next=newnode;
			}
		}
	}
}

void deletion()
{		
	int choice;
	printf("1.Delete at beginning\n2.Delete at ending\n3.Delete at position\n");	
	printf("Enter your choice:");
	scanf("%d",&choice);
	if(tail==NULL)
	{
		printf("List is empty nothing to delete\n");
	}
	else if(tail->next==tail)
	{
		temp=tail->next;
		tail=NULL;
		free(temp);
	}
	else
	{	
		struct node*previous;
		temp=tail->next;		
		if(choice==1)
		{
			tail->next=temp->next;
			free(temp);
		}
		else if(choice==2)
		{
			while(temp->next!=tail->next)
			{
				previous=temp;
				temp=temp->next;
			}
			previous->next=tail->next;
			tail=previous;
			free(temp);
		}
		else if(choice==3)
		{
			int pos;
			printf("Enter the position:\n");
			scanf("%d",&pos);
			int length=1;
			while(temp->next!=tail->next)
			{
				temp=temp->next;
				length++;
			}
			temp=tail->next;
			if(pos<1 || pos>length)
			{
				printf("Invalid position");
			}
			else if(pos==1)
			{
				tail->next=temp->next;
				free(temp);
			}
			else 
			{	
				int i=1;
				temp=tail->next;
				while(i<pos)
				{
					previous=temp;
					temp=temp->next;
					i++;
				}
				if(pos==length)
				{
					previous->next=tail->next;
					tail=previous;
					free(temp);
				}
				else 
				{	
					previous->next=temp->next;
					free(temp);
				}
			}
		}
	}
}

void reverse()
{	
	struct node*prev,*nextnode;
	if(tail==NULL)
	{
		printf("list is empty\n");
	}
	else if(tail==tail->next)
	{
		printf("%d ",tail->data);
	}
	else 
	{
		temp=tail->next;
		nextnode=temp->next;
		while(temp!=tail)
		{
			prev=temp;
			temp=nextnode;
			nextnode=temp->next;
			temp->next=prev;
		}
		nextnode->next=tail;
		tail=nextnode;
	}
}


