#include<stdio.h>
#include<stdlib.h>

struct node
{	
	struct node*prev;
	int data;
	struct node*next;
}*head,*tail,*newnode,*temp;


void create(int n);
void display();
int count();
void insertion( );
void deletion();
void reverse();


int main()
{	
	int n,choice=1;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	create(n);
	printf("\nLinked list before operations:\n");
	display();
	while(choice){
	
		printf("\n1.To perform Insertion\n2.To perform Deletion\n3.To reverse the linked list\n4.To exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{	
			case 1:insertion();
				break;
			case 2:deletion();
				break;
			case 3:reverse();
				break;
			case 4:printf("\nPROGRAM ENDED");
				exit(0);
			default:printf("Invalid choice:");
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
		printf("enter the data of node %d :",i);
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next=NULL;
		if(head==NULL)
		{
			head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
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
	printf("\n");
}

int count()
{	int c=0;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}

void insertion()
{	
	int choice;
	temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to insert:");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	if(head==NULL)
	{	
		newnode->next=NULL;	
		head=tail=newnode;	
	}
	else
	{	
		printf("\n1.Insert at beginning\n2.Insertion at position\n3.Insert at end\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			head->prev=newnode;
			newnode->next=head;
			head=newnode;
		}
		if(choice==2)
		{	
			int length=count();
			temp=head;
			int i=1,pos;
			printf("\nEnter the position:");
			scanf("%d",&pos);
			if(pos<1 || pos>length)
			{
				printf("\nInvalid position\n");
			}
			else
			{
				while(i<pos-1)
				{
					temp=temp->next;
					i++;
				}
				if(pos==1)
				{	
					temp->prev=newnode;
					newnode->next=temp;
					head=newnode;
					temp=temp->next;
				}
				else
				{
					newnode->next=temp->next;
					newnode->prev=temp;
					temp->next->prev=newnode;
					temp->next=newnode;
				}
				
			}
		}
		if(choice==3)
		{
			newnode->prev=tail;
			newnode->next=NULL;
			tail->next=newnode;
			tail=newnode;
		}				
				
	}
	printf("\nLinked list after insertion:\n");
	display();
}

void deletion()
{	
	int choice;
	printf("\n1.Delete at beginning\n2.Delete at position\n3.Delete at end\n");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	temp=head;
	if(head==NULL)
	{
		printf("\nList is empty nothing to delete\n");
	}
	else
	{
		if(choice==1)
		{	
			if(head->next==NULL)
			{	
				head=tail=NULL;
				free(temp);
			}
			else{
				head=head->next;
				head->prev=NULL;
				free(temp);
			}
		}
		if(choice==2)
		{		
			int pos,i=1;
			printf("\nEnter the position:");
			scanf("%d",&pos);
			int length=count();
			if(pos==1)
			{
				head=head->next;
				head->prev=NULL;
				free(temp);
			}
			else if(pos==length)
			{
				temp=tail;
				tail->prev->next=NULL;
				tail=tail->prev;
				free(temp);
			}
			else
			{
				while(i<pos)
				{
					temp=temp->next;
					i++;
				}
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				free(temp);
			}
		}
		if(choice==3)
		{		
			temp=tail;
			if(tail->prev==NULL)
			{	
				head=tail=NULL;
				free(temp);
			}
			else{
				tail->prev->next=NULL;
				tail=tail->prev;
				free(temp);
			}
		}
	}
	printf("\nLinked list after deletion is:\n");
	display();
}

void reverse()
{	
	
	struct node*nextnode;
	if(head==NULL)
	{
		printf("\nList is empty:")	;
	}
	else if(head==tail)
	{
		printf("%d ",temp->data);
	}
	else
	{	temp=head;
		while(temp!=NULL){
	
			nextnode=temp->next;
			temp->next=temp->prev;
			temp->prev=nextnode;
			temp=nextnode;
		}
		temp=head;
		head=tail;
		tail=temp;
	}
	printf("The reverse of linkd list is:\n");
	display();
}


