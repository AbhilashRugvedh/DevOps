#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *create();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);


void main()
{
	struct node *root;
	root=0;
	root=create();
	
	printf("Inorder Binary Tree Is :");
	inorder(root);
	printf("\n");
	printf("Preorder Binary Tree Is :");
	preorder(root);
	printf("\n");
	printf("Postorder Binary Tree Is :");
	postorder(root);	
}


struct node *create()
{
	int x;
	
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter Root Data And (-1 For No Node ) :");
	scanf("%d",&x);
	
	if(x==-1)
	{
		return 0;
	}
	newnode->data=x;
	printf("Enter Left Child  Of %d:",x);
	newnode->left=create();
	
	printf("Enter Right Child of %d:",x);
	newnode->right=create();
	
	return newnode;
	
}


void inorder(struct node *root)
{
	if(root==NULL)
	{
		return ;
	}
	
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
}


void preorder(struct node *root)
{
	if(root==NULL)
	{
		return ;
	}
	
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}


void postorder(struct node *root)
{
	if(root==NULL)
	{
		return ;
	}
	
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}
