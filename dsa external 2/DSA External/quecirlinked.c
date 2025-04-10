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

int main()
{
    enqueue(4);
    enqueue(9);
    enqueue(-2);
    enqueue(78);
    dequeue();
    enqueue(0);
    display();
    enqueue(100000);
    display();    
    return 0;
}

void enqueue(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(front==0)
    {
        front=rear=newnode;
        rear->next=newnode;
    }
    else
    {
        rear->next=newnode;
        newnode->next=front;
        rear=newnode;
    }
}

void dequeue()
{   
    struct node*temp;
    temp=front;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else if(front==rear)
    {
        front=rear=0;
        free(temp);
    }
    else
    {
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void display()
{
    struct node*temp;
    if(front==0)
    {
        printf("queue is empty\n");
    }
    else
    {
        temp=front;
        while(temp->next!=front)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d \n",temp->data);
    }
}

void peek()
{
    if(front==0)
        printf("Queue is empty\n");
    else
    {
        printf("The front element in the queue is %d",front->data);    
    }
}

