#include<stdio.h>
#define MAX_SIZE 100

int tree[MAX_SIZE];

// Function to Initilize The Tree 

void initializeTree()
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		tree[i]=-1;  // -1 represents an Empty Tree
	}
}

// Fucntion to insert a value Into the Tree

void insert(int value,int index)
{
	if(tree[index]==-1)
	{
		tree[index]=value;
		return ;
	}
	if(value<tree[index])
	{
		insert(value,2*index+1);  // Go To The Left Child
	}
	else
	{
		insert(value,2*index+2); // Go to the Right Child 
	}
}

// Function To Print Tree in Inorder Travseral

void printinorder(int index)
{
	if(index>=MAX_SIZE || tree[index]==-1)
	{
		return ;
	}
	printinorder(2*index+1); // print Left Subtree
	printf("%d ",tree[index]); // print Current Node
	printinorder(2*index+2); // print right Sub Tree
	
}

int main()
{
	initializeTree();
	
	insert(50,0);
	insert(30,0);
	insert(70,0);
	insert(20,0);
	insert(40,0);
	insert(60,0);
	insert(80,0);
	
	printf("In-Order Travseral of The Binary Tree : ");
	printinorder(0);
	
	return 0;
}
