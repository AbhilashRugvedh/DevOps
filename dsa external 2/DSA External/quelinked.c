//queue implementation with linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*front=0,*rear=0;
void enqueue(int x);
void dequeue();
void display();
void peek();


void enqueue(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(front==0 && rear==0)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
int main()
{
    enqueue(2);
    enqueue(7);
    enqueue(56);
    enqueue(-34);
    dequeue();
    display();
    enqueue(300);
    dequeue();
    display();
    peek();
    return 0;
}

void dequeue()
{   
    struct node*temp;
    temp=front;
    if(front==0)
    {
        printf("Queue is empty\n");
    }
    else if (front==rear)
    {
        front=rear=0;
        free(temp);
    }
    else
    {
        front=front->next;
        free(temp);
    }
}

void display()
{
    if(front==0)
    {
        printf("The queue is empty\n");
    }
    else
    {   
        printf("The queue is\n");
        struct node*temp;
        temp=front;
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void peek()
{
    if(front==NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("\nThe front element in th queue is %d\n",front->data);
    }
}


