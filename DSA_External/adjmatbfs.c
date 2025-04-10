#include<stdio.h>
void breadth_first_search(int);
#define MAX 100
int graph[MAX][MAX]={0};
int visited[MAX]={0};
int no_vertices;

void main()
{	
    int numvertices,edges,src,dest,vertex;
    printf("Enter the number of vertices:");
    scanf("%d",&no_vertices);
    graph[no_vertices][no_vertices];
    
   printf("Enter the adjacency matrix:\n");
    for(int i=0;i<no_vertices;i++)
    {
  	for(int j=0;j<no_vertices;j++)
  	{
  		scanf("%d",&graph[i][j]);
  	}
    }	
    printf("Enter the starting vertex to search for BFS:");
    scanf("%d",&vertex);
    printf("\nBFS Traversal : ");
    breadth_first_search(vertex);
}

void breadth_first_search(int vertex)
{
    int queue[MAX], rear = 0, front = 0, i;
    queue[rear++] = vertex;
    visited[vertex] = 1;
    while(front<rear)
    {
        int visit = queue[front++];
        printf("%d ",visit);
        for(i = 0; i<MAX; i++)
        {
            if(graph[visit][i]==1 && visited[i]==0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }       
    }
}

