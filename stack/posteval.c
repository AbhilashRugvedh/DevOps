#include<stdio.h>
#include<ctype.h>

#define MAX 10

int stack[MAX];
int top = -1;/* top of the stack*/
void push(int);
int pop();

int evaluate_postfix(char po_exp[]){
    int a,b, result;
    int i;
    for(i= 0; po_exp[i]!='\0';i++){
        if(isdigit(po_exp[i]))
            push(po_exp[i]-'0'); /*converts the digit character into digit(integer).for e.g.  '5'-'0' => 53-48 (their ascii values) = 5.*/
        else{
            a = pop();				/*pop top two digits from stack*/
            b = pop();
            switch(po_exp[i])
            {
		case '+': result=b+a;   break;
                case '-': result=b-a;   break;
                case '*': result=b*a;   break;
                case '/': result=b/a;   break;
            }
            push(result);			/*push the result back into stack*/
        }
    }
    return pop();
}

void push(int element){
	if(top >= MAX-1){			/*When stack is full*/
		printf("Stack overflow\n");
		return;
	}
	stack[++top] = element;			/*When stack is not full*/
}

int pop(){
	if(top < 0){				/*When stack is empty*/
        	printf("Stack underflow");
        	return 0;
	}
	return stack[top--];
}


int main(){
	char po_exp[10];
	int res;
	printf("enter postfix expression\n");
	scanf("%s", po_exp );
	res = evaluate_postfix(po_exp);
	printf("Result: %d \t", res);
	return 0;
}
