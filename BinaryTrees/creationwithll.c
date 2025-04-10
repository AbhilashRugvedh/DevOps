#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create();
void inorder(struct node *root);

int main()
{
    struct node *root;
    root=0;
    root=create();

}

struct node *create()
{
    int x;
    
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Root Value:");
    scanf("%d",&x);

    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("Enter Left Child :");
    newnode->left=create();

    printf("Enter Right Child :");
    newnode->right=create();

    return newnode;
}

