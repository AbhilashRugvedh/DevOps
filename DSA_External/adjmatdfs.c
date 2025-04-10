#include<stdio.h>
#define MAX 6
int graph[MAX][MAX] = {0},visited[MAX] = {0};
void depth_first_search(int);
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
    printf("Enter the starting vertex to serch for DFS:");
    scanf("%d",&vertex);                  
    depth_first_search(vertex);
}


void depth_first_search(int vertex)
{
    int stack[MAX],top = -1;
    stack[++top] = vertex;
    while(top>=0)
    {
        int element = stack[top--];
        if(visited[element]==0)
        {
            visited[element] = 1;
            printf("%d ",element);
        }
        for(int i = 0; i<MAX; i++)
        {
            if(graph[element][i]==1 && visited[i]==0)
            {
                stack[++top] = i;
            }
        }
    }
}
