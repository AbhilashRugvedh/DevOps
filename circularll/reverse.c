#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*temp,*head,*newnode,*tail,*temp1,*temp2,*new;

void create();
void reverse();
void display();

void main()
{
	create();
	printf("Original List Is : ");
	display();
	
	printf("\n");
	reverse();
	printf("Reversed List is  :");
	display();
	
}

void create()
{
	int n,i;
	printf("Enter Size Of Linked List :");
	scanf("%d",&n);
	
	head=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data For Node 1 :");
	scanf("%d",&head->data);
	
	
	head->next=head;
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&newnode->data);
		
		temp->next=newnode;
		tail=newnode;
		tail->next=head;
		temp=temp->next;
	}
}

void reverse()
{
	
	temp=head;
	head=tail;
	tail=temp;
	temp2=tail->next;
	new=temp2->next;
	
	while(temp2!=tail)
	{
		temp=temp2;
		temp2=new;
		new=temp2->next;
		temp2->next=temp;
		
	}
	new->next=tail;
	tail=new;
	
	
}		
	
















void display()
{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}

