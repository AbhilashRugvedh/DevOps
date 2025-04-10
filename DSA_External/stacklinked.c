#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
	int data;
	struct node*next;
}*top=0,*temp;

int main()
{
int n;
	int choice,element;
	printf("Stack menu:\n");
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.To display\n");
	printf("4.To exit\n");
	while(1)
	{	
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 	printf("Enter the element which you want to push into the stack:");
				scanf("%d",&element);
				push(element);
				break;
			case 2: 	pop();
				break;
			case 3:  display();
				break;
			case 4:  printf("Exiting the program\n");
				return 0;
			default : printf("Enter correct choice\n");
		}
	}
}

void push(int x)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

void pop()
{
	if(top==0)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("Popped element is %d \n",top->data);
		temp=top;
		top=top->next;
		free(temp);
	}
}

void display()
{	
	temp=top;
	if(top==0)
	{
		printf("stack is empty\n");
	}
	else
	{
		while(temp!=0)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

	
