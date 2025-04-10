#include<stdio.h>
#define N 20
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x);
void dequeue();
void display();
void peek();


void enqueue(int x)
{   
    if(rear==N-1)
    {
        printf("Over flow...!! Queue is full");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
int main()
{   
    enqueue(-3);
    enqueue(4);
    enqueue(0);
    dequeue();
    enqueue(56);
    enqueue(-90);
    display();
    return 0;
}


void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
    }
    else if(front==rear)
    {
        printf("The deleted element is %d",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("The deleted element from the queue is %d \n",queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty ");
    }
    else
    {   
        printf("The queue is \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
    
}
