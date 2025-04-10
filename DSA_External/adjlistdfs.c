#include<stdio.h>
#include<stdlib.h>
int no_vertices;
struct node
{
	int data;
	struct node *next;
};

void readGraph(struct node*adj[]);
void dfs(struct node*adj[],int start,int visited[]);

int main()
{	
	printf("Enter the number of vertices:");
	scanf("%d",&no_vertices);
	struct node*adj[no_vertices];
	for(int i=0;i<no_vertices;i++)
	{
		adj[i]=NULL;
	}
	readGraph(adj);
	int visited[no_vertices],start;
	for(int i=0;i<no_vertices;i++)
	{
		visited[i]=0;
	}
	printf("Enter the vertex where you want to start to search for DFS:");
	scanf("%d",&start);
	dfs(adj,start,visited);
	return 0;
}

void readGraph(struct node*adj[])
{
	struct node*newnode,*tail;
	int k,x;
	for(int i=0;i<no_vertices;i++)
	{
		printf("How many vertices are adjacent to %d :",i);
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{	
			newnode=(struct node*)malloc(sizeof(struct node*));
			printf("Enter the %d neighbour of %d:",j,i);
			scanf("%d",&x);
			newnode->data=x;
			newnode->next=NULL;
			if(adj[i]==NULL)
			{
				adj[i]=tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
		}
	}
}

void dfs(struct node*adj[],int vertex,int visited[])
{	
	int stack[no_vertices], top=-1;
	stack[++top]=vertex;
	while(top>=0)
	{
		int current=stack[top--];
		struct node*ptr=adj[current];
		if(visited[current]==0)
		{
			visited[current]=1;
			printf("%d ",current);
		}
		while(ptr!=NULL)
		{
			if(visited[ptr->data]==0)
			{
				stack[++top]=ptr->data;
			}
			ptr=ptr->next;	
		}
	}
}

			





