#include<stdio.h>
#define MAX 6
int adj[MAX][MAX] = {0},visited[MAX] = {0};
void depth_first_search(int);
void addEdge(int,int);
void addEdge(int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}
void depth_first_search(int vertex)
{
    int stack[MAX],top = -1;
    stack[++top] = vertex;
    while(top>=0)
    {
        int visit = stack[top--];
        if(!visited[visit])
        {
            visited[visit] = 1;
            printf("%d ",visit);
        }
        for(int i = 0; i<MAX; i++)
        {
            if(adj[visit][i] && !visited[i])
            {
                stack[++top] = i;
            }
        }
    }
}
void main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);                        
    printf("DFS Traversal : ");
    depth_first_search(0);
}
