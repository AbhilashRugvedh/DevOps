#include<stdio.h>
#define MAX 6
int graph[MAX][MAX] = {0},visited[MAX] = {0};
void depth_first_search(int);
void addEdge(int,int);
void addEdge(int src, int dest)
{
    graph[src][dest] = 1;
    graph[dest][src] = 1;
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
        hgr}
        for(int i = 0; i<MAX; i++)
        {
            if(graph[element][i]==1 && visited[i]==0)
            {
                stack[++top] = i;
            }
        }
    }
}
void main()
{
    int numvertices,edges,src,dest,vertex;
    printf("Enter the number of vertices:");
    scanf("%d",&numvertices);
    int graph[numvertices][numvertices];
    
    printf("Enter the number of edges:");
    scanf("%d",&edges);
   
    for(int i=0;i<edges;i++)
    {
    	printf("Enter the source:");
    	scanf("%d",&src);
    	printf("Enter the destination:");
    	scanf("%d",&dest);
    	addEdge(src,dest);
    }
    printf("Enter the starting vertex to serch for DFS:");
    scanf("%d",&vertex);                  
    depth_first_search(vertex);
}
