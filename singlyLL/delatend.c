#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*temp,*head,*new,*temp1;

void create();
void display();
void dltatend();
//void display1();

int main()
{
	create();
	printf("Original List Is:");
	display();
	printf("\n");
	dltatend();
	printf("List After Deleting An Element At End :");
	display();
}

void create()
{
	int n,i;
	printf("Enter Size of The List :");
	scanf("%d",&n);
	head=malloc(sizeof(struct node));
	printf("Enetr Data For Node 1 :");
	scanf("%d",&head->data);
	head->next=NULL;
	
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		new=malloc(sizeof(struct node));
		printf("Enetr Data For Node %d :",i);
		scanf("%d",&new->data);
		
		temp->next=new;
		temp=temp->next;
		new->next=NULL;
		
	}
	
	
	
}



void dltatend()
{
	temp=head;
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
}
void display()
{
	
	temp1=head;
	while(temp1!=NULL)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->next;
	}
}
		
		
	
