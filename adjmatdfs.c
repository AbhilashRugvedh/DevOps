#include<stdio.h>

#define MAX 100
int graph[MAX][MAX]={0};
int visited[MAX]={0};
int numvertices;
void depth_first_search(int vertex);
void main()
{	
    int vertex;
    printf("Enter the number of vertices:");
    scanf("%d",&numvertices);
    printf("Enter the adjacency matrix:\n");
   for(int i=0;i<numvertices;i++)
   {
   	for(int j=0;j<numvertices;j++)
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
        for(int i = 0; i<numvertices; i++)
        {
            if(graph[element][i]==1 && visited[i]==0)
            {
                stack[++top] = i;
            }
        }
    }
}
