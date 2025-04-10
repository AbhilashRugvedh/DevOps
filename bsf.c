#include<stdio.h>
#include<stdlib.h>

// Structure o represent a node in the adjucent list

struct node
{
	int data;
	struct node *next;
};

// Structure to represent the graph with an array of adjacency Lists

struct graph
{
	int numvertices;
	struct node **adjlists;
	int *visited;
};

// Create Newnode

struct node *createnode(int data)
{
	struct node* newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

// Create Graph With Vertices

struct graph* creategraph(int n)
{
	struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
	=
	graph->numvertices=n;
	graph->adjlists=(struct node**)malloc(n *sizeof(struct node*));
	graph->visited=(int *)malloc(n*sizeof(int));
	
	for(int i=0;i<n;i++)
	{
		graph->adjlists[i]=NULL;
		graph->visited[i]=0;
	}
	return graph;
}

// Add an edge to an undirected graph

void addedge(struct graph* graph,int src,int dest)
{
	struct node* newnode=createnode(dest);
	newnode->next=graph->adjlists[src];
	graph->adjlists[src]=newnode;
	
	// Since it is an undirected graph , add an edge from dest to src as well
	
	newnode=createnode(src);
	newnode->next=graph->adjlists[dest];
	graph->adjlists[dest]=newnode;
}

// Function to perform Breadth First search

void bfs(struct graph* graph,int startvertex)
{
	//create a Queue For BFS
	int* queue=(int *)malloc(graph->numvertices * sizeof(int));
	int front=0;
	int rear=0;
	
	// Mark the starting vertex as visited and enqueue it
	
	graph->visited[startvertex]=1;
	queue[rear++]=startvertex;
	
	while(front<rear)
	{
		// Dequeue a vertex from the queue and print it
		int currentvertex=queue[front++];
		printf("%d ",currentvertex);
		
		// Get all Adjecent vertices of the dequeued vertex
		
		struct node* temp=graph->adjlists[currentvertex];
		while(temp!=NULL)
		{
			int adjvertex=temp->data;
			if(graph->visited[adjvertex]==0)
			{
				graph->visited[adjvertex]=1;
				queue[rear++]=adjvertex;
			}
			temp=temp->next;
		}
	}
	free(queue);
}

// Driver program to test the BFS implementation

int main()
{
	int numvertices=6;
	struct graph* graph=creategraph(numvertices);

	addedge(graph,0,1);
	addedge(graph,0,2);
	addedge(graph,1,2);
	addedge(graph,1,3);
	addedge(graph,2,3);
	addedge(graph,3,4);
	addedge(graph,4,5);
	
	int startvertex=0;
	printf("BFS Traversal :");
	bfs(graph,startvertex);
	printf("\n");
	
	free(graph->adjlists);
	free(graph->visited);
	free(graph);
	
	return 0;
}
