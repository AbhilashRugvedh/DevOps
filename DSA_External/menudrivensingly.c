#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head,*temp,*newnode;


void create(int n);
void display();
int count();
void insert_at_beg(); 
void insert_at_end();
void insert_at_pos();
void delete_at_beg();
void delete_at_end();
void delete_at_pos();
void reverse();

int main()
{	
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("Linked list before operations:\n");
	display();
	int choice=1;
	while(choice)
	{
	
		printf("\n1.Insert at beginning\n2.Insert at ending\n3.Insert at position\n4.Delete at begininng\n5.Delete at ending\n6.Delete at position\n7.To reverse the linked list\n8.To EXIT\n");
		printf("Enter your choice to perform the operations:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	insert_at_beg();
				printf("Linked list after inserting at beginning is :\n");
				display();
				break;
			case 2: 	insert_at_end();
				printf("Linked list after inserting at ending is :\n");
				display();
				break;
			case 3:	insert_at_pos();
				printf("Linked list after inserting at position is : \n");
				display();
				break;
			case 4:	delete_at_beg();
				printf("Linked list after deleting at beginning is :\n");
				display();
				break;
			case 5:	delete_at_end();
				printf("Linked list after deleting at ending is :\n");
				display();
				break;
			case 6: 	delete_at_pos();
				printf("Linked list after deleting at position is :\n");
				display();
				break;
			case 7:  reverse();
				printf("Linked list after reversing is :\n");
				display();
				break;
			case 8:	printf("PROGRAM ENDED:\n");
				exit(0);
				break;
			default: printf("ENTER CORRECT CHOICE:\n");
				break;
		}
	}
}


void create(int n)
{
	head=NULL;
	for(int i=1;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data of node %d :",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else 
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
}
			 
	
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int count()
{	
	int c=0;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}

void insert_at_beg()
{	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of newnode:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{	
		newnode->next=head;
		head=newnode;
	}
}

void insert_at_end()
{	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of newnode:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else 
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void insert_at_pos()
{	
	int pos;
	printf("Enter the position to insert:\n");
	scanf("%d",&pos);
	int length=count();
	newnode=(struct node*)malloc(sizeof(struct node));
	if(pos>length || pos<1)
	{
		printf("Cant insert\n");
	}
	else if(head==NULL)
	{
		head=newnode;
	}
	else if(pos==1)
	{
		insert_at_beg();
	}
	else 
	{	
		temp=head;
		printf("Enter the data of newnode:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		int i=1;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

void delete_at_beg()
{	
	temp=head;
	if(head==NULL)
	{
		printf("Can't delete list is empty\n");
	}
	else 
	{	
		head=temp->next;
		free(temp);
	}
}

void delete_at_end()
{	
	if(head==NULL)
	{
		printf("List is empty:\n");
	}
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{	
		temp=head;
		while(temp->next->next!=NULL)
		{	
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}

void delete_at_pos()
{
	int pos;
	int length=count();
	printf("Enter the position to delete:\n");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("Can't delete list is empty\n");
	}
	else if(pos>length || pos<1)
	{
		printf("Can't delete\n");
	}
	else if(pos==1)
	{
		delete_at_beg();
	}
	else if(pos==length)
	{
		delete_at_end();
	}
	else 
	{	
		int i=1;
		struct node*ptr;
		temp=head;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		ptr=temp->next;
		temp->next=ptr->next;
		free(ptr);
	}
}

void reverse()
{
	struct node*prevnode,*currentnode;
	prevnode=NULL;
	currentnode=temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		currentnode->next=prevnode;
		prevnode=currentnode;
		currentnode=temp;
	}
	head=prevnode;
}		
