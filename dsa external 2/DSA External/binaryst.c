#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*right;
	struct node*left;
};

void inorder(struct node*root);
void preorder(struct node*root);
void postorder(struct node*root);
struct node*CreateBST(struct node *root,int item);
struct node*insert(struct node*node,int item);
struct node*search(struct node*root,int item);
struct node*Delete(struct node *root,int item);
int getrightmin(struct node*root);

int main()
{
	int item,n,choice;
	struct node*root;
	root=NULL;
	printf("How many nodes for BST:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("Enter the data of node %d:",i);
		scanf("%d",&item);
		root=CreateBST(root,item);
	}
	printf("MENU\n");
	printf("1.Insertion\n2.Deletion\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.EXIT");
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:  printf("Enter the element to insert:");
				scanf("%d",&item);
				insert(root,item);
				break;
			case 2:  printf("Enter the data to delete:");
				scanf("%d",&item);
				Delete(root,item);
				break;
			case 3:  printf("Enter key to search:");
				scanf("%d",&item);
				search(root,item);
				if (search(root, item) == NULL)
					printf("%d not found\n", item);
				else
					printf("%d found\n", item);
				break;
			case 4:  printf("Inorder traversal is :\n");
				inorder(root);
				printf("\n");
				break;
			case 5:  printf("Preorder traversal is :\n");
				preorder(root);
				printf("\n");
				break;
			case 6:  printf("Postorder traversal is :\n");
				postorder(root);
				printf("\n");
				break;
			case 7: printf("program ended:\n");
			return 0;
			default:printf("Enter valid  choice!!");
		}
	}

}

struct node*CreateBST(struct node *root,int item)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->left=root->right=NULL;
		root->data=item;
		return root;
	}
	else
	{
		if(item < root->data)
			root->left=CreateBST(root->left,item);
			
		else if(item > root->data)
			root->right=CreateBST(root->right,item);
			
		else
			printf("Duplicates are not allowed!!!");
		
		return root;
	}
}

struct node *insert(struct node*node,int item)
{
	if(node==NULL)
	{
		node=(struct node*)malloc(sizeof(struct node));
		node->left=node->right=NULL;
		node->data=item;
		return node;
	}
	else
	{
		if(item < node->data)
			node->left=insert(node->left,item);
		else if(item > node->data)
			node->right=insert(node->right,item);
		return node;
	}
}

struct node*search(struct node*root,int item)
{
	if(root==NULL || root->data==item)
		return root;
	else if(item < root->data)
		return search(root->left,item);
	else
		return search(root->right,item);
}

struct node*Delete(struct node*root,int item)
{
	if(root==NULL)
		return NULL;
	if(item < root->data)
		root->left=Delete(root->left,item);
	else if(item > root->data)
		root->right=Delete(root->right,item);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->right==NULL)
		{
			struct node*temp=root->left;
			free(root);
			return temp;
		}
		else if(root->left==NULL)
		{
			struct node*temp=root->right;
			free(root);
			return temp;
		}
		else
		{
			int rightmin=getrightmin(root->right);
			root->data=rightmin;
			root->right=Delete(root->right,item);
		}
		
	}
	return root;
}

int getrightmin(struct node*root)
{
	struct node*temp=root;
	while(temp->left!=NULL)
	{	
		temp=temp->left;
	}
	return temp->data;
}

void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
