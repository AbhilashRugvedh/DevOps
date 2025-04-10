#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int);
void dequeue();
void display();

int main()
{
    enqueue(3);
    enqueue(-5);
    enqueue(87);
    enqueue(-44);
    enqueue(78);
    display();
    dequeue();
    enqueue(89);
    display();
    enqueue(45);
    
    return 0;
}

void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front)
    {
        printf("queue is full\n");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%N;
    }
 }

 void display()
 {
    if(front ==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {   
        printf("Queue is:\n ");
        int i=front;
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d ",queue[i]);//queue[rear]

    }
 }