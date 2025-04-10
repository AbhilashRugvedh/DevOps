#include<stdio.h>
#define MAX 6
int adj[MAX][MAX] = {0} , visited[MAX] = {0};
void breadth_first_search(int);
void addEdge(int,int);
void main()
{
    addEdge(0, 1); 
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    printf("BFS Traversal : ");
    breadth_first_search(0);
}
void addEdge(int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}
void breadth_first_search(int vertex)
{
    int queue[MAX], rear = 0 , front = 0, i;
    queue[rear++] = vertex;
    visited[vertex] = 1;
    while(front<rear)
    {
        int visit = queue[front++];
        printf("%d ",visit);
        for(i = 0; i<MAX; i++)
        {
            if(adj[visit][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
