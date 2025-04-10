#include<stdio.h>
#include<stdlib.h>
int no_vertices;
struct node
{
	int data;
	struct node *next;
};

void readGraph(struct node*adj[]);
//void printGraph(struct node*adj[]);
void bfs(struct node*adj[],int start,int visited[]);

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
	//printGraph(adj);
	int visited[no_vertices],start;
	for(int i=0;i<no_vertices;i++)
	{
		visited[i]=0;
	}
	printf("ENter the vertex where you want to start to search for BFS:");
	scanf("%d",&start);
	bfs(adj,start,visited);
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

void bfs(struct node*adj[],int start,int visited[])
{
	int queue[no_vertices],front=-1,rear=-1;
	struct node*ptr;
	queue[++rear]=start;
	front++;
	
	printf("\n The BFS traversal from %d is :",start);
	while(front<=rear)
	{
		start=queue[front++];
		ptr=adj[start];
		visited[start]=1;
		printf("%d ",start);
		while(ptr!=NULL)
		{
			if(visited[ptr->data]!=1)
			{
				queue[++rear]=ptr->data;
				visited[ptr->data]=1;
			}
			ptr=ptr->next;
		}
	}
}	

/*void printGraph(struct node*adj[])
{
	struct node*temp;
	for(int i=0;i<no_vertices;i++)
	{
		printf("\nThe adjacent vertices of %d are:\n",i);
		temp=adj[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}*/
			
			
			
