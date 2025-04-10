#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int  precedence(char op);
char* infixTopost(char* infix);

int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default: return -1;
    
    }
}

char* infixTopost(char* infix)
{   
    int len=strlen(infix);
    char* postfix=(char *)malloc(sizeof(char));
    int j=0;
    char stack[len];
    int top=-1;
    for(int i=0;i<len;i++)
    {
        if(infix[i]==' ' || infix[i]=='\t')
            continue;
        else if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
            stack[++top]=infix[i];
        else if(infix[i]==')')
        {
            while(top>-1 && stack[top]!='(')
            {
                postfix[j++]=stack[top--];
            }
            top--;
        }
        else
        {
            while( top>-1 && precedence(stack[top])>=precedence(infix[i]))
            {
                postfix[j++]=stack[top--];
            }
            stack[++top]=infix[i];
        }
    }
    while(top>-1)
    {
        if(stack[top]=='(')
            return "invalid expression";
        postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{   
    char infix[100];
    printf("Enter the infix expression to convert it into an post fix expression:");
    fgets(infix,100,stdin);
    char* postfix=infixTopost(infix);
    printf("The postfix expression is %s",postfix);
    return 0;
}