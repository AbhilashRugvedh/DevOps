#include<stdio.h>
void breadth_first_search(int);
#define MAX 100

int graph[MAX][MAX]={0};
int visited[MAX]={0};
int numvertices;

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
	printf("Enter the starting vertex for bfs:");
	scanf("%d",&vertex);
	 breadth_first_search(vertex);

}
   
void breadth_first_search(int vertex)
{
    int queue[numvertices], rear = 0 , front = 0, i;
    queue[rear++] = vertex;
    visited[vertex] = 1;
    while(front<rear)
    {
        int visit = queue[front++];
        printf("%d ",visit);
        for(i = 0; i<numvertices; i++)
        {
            if(graph[visit][i]==1 && visited[i]==0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }       
    }
}

