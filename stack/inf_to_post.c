#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 100

//  Function to return precedence of Operators
int precedence(char operator)
{
	switch(operator)
	{
		case '+':
		case '-' :
			return 1;
		case '*' :
		case '/' :
			return 2;
		case '^' :
			return 3;
		default :
			return -1;
	}
} 

// main function to convert infix to postfix

char* inftopost(char* infix)
{
	int i,j;
	int len=strlen(infix);
	char* postfix=(char*)malloc(sizeof(char));
	int stack[size];
	int top=-1;
	j=0;
	
	for(i=0;i<len;i++)
	{	
		if(infix[i]==' ' || infix[i]=='\t')
		{
			continue;
		}
		// if the scanned character is operand
		// then add it to postfix expression
		if(isalnum(infix[i]))
		{
			postfix[j++]=infix[i];
		}
		// if the scanned character is '('
		// then add it to stack;
		else if(infix[i]=='(')
		{
			stack[++top]=infix[i];
		}
		// if the scanned character is ')'
		// then pop the stack until find '('
		else if(infix[i]==')')
		{
			while(top>-1 && stack[top]!='(')
			{
				postfix[j++]=stack[top--];
			}
			stack[top++];
		}
		// if the scanned character is operator 
		// then push into the stack
		else
		{
			while(top>-1 && precedence(stack[top])>=precedence(infix[i]))
			{
				postfix[j++]=stack[top--];
			}
			stack[++top]=infix[i];
		}
	}
	while(top>-1)
	{
		if(stack[top]=='(')
		{
			printf("Invalid Expression ");
		}
		postfix[j++]=stack[top--];
	}
	
	postfix[j]='\0';
	return postfix;

}

int main()
{
	char infix[size];
	printf("Enter Infix Expression :");
	scanf("%s",infix);
	
	char* postfix=inftopost(infix);
	printf("%s\n",postfix);
	free(postfix);
	return 0;
}
			
			
