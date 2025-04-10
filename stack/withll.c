#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct node
{
	int data;
	struct node *next;
}*temp,*newnode,*top=0;

int main()
{
	int n,i;
	printf("Enter The Size Of The Stack :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		push();
	}
	display();
	printf("\n");
	pop();
	display();
}

void push()
{
	int x;
	printf("Enter Data To The Stack :");
	scanf("%d",&x);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

void pop()
{
	temp=top;
	if(top==0)
	{
		printf("Stack Is Empty :");
	}
	else
	{
		top=top->next;
		printf("The Deleted Element Is  :%d\n",temp->data);
		free(temp);
	}
}


void display()
{
	temp=top;
	if(top==NULL)
	{
		printf("Stack Is Empty :");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
	}
}
