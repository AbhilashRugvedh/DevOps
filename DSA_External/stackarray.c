#include<stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top=-1;

void push(int element,int n);
int pop();
void display();

int main()
{	
	int n;
	printf("Enter the size of stack\n");
	scanf("%d",&n);
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
				push(element,n);
				break;
			case 2: 	element=pop();
				if(element!=-1)
				{
					printf("The element popped from stack is %d\n",element);
				}
				break;
			case 3:  display();
				break;
			case 4:  printf("Exiting the program\n");
				return 0;
			default : printf("Enter correct choice\n");
		}
	}
	return 0;
}

void push(int element,int n)
{	
	if(top==n-1)
	{
		printf("STACK Overflow!.Stack is full can not push");
		return ;
	}
	top++;
	stack[top]=element;
	printf("Element %d pushed into the stack\n",element);
}

int pop()
{
	if(top==-1)
	{
		printf("STACK underflow!.Stack is empty\n");
		return -1;
	}
	int element=stack[top];
	top--;
	return element;
}

void display()
{
	if(is_empty())
	{
		printf("Stack is empty\n");
		return ;
	}
	printf("The elements in the stack are:\n");
	int i;
	for(int i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
				
		

