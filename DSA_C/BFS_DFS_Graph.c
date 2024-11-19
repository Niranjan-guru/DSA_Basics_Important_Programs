#include <stdio.h>
#define MAX 100

void bfs(int adj[][MAX], int visited[], int start){
    int queue[MAX], front = -1, rear = -1,i;
    queue[++rear] = start;//enqueue the first starting vertex of the graph
    visited[start] = 1;
    while(rear != front){
        start = queue[++front];//take out each vertex connected to the original graph
        for(i=0;i<MAX-1;i++){
            if(adj[start][i] == 1 && visited[i] == 0){ //check whether the edge is available for the chosen vertex
                visited[i] = 1;//and also whether the vertex is previously visited or not
                queue[++rear] = i;//if both the above conditions satisfy then proceed to enqueuing the new vertex and update the visited array.
            }
        }
    }
}


void dfs(int adj[][MAX], int visited[], int start){
    int stack[MAX], top = -1,i;
    stack[++top] = start;
    visited[start] = 1;
    while(top != -1){
        start = stack[top];
        for(i=0; i<MAX-1; i++){
            if(adj[start][i] == 1 && visited[i] == 0){
                stack[++top] = i;
                visited[i] == 1;
                printf("%c\t  "i+65);//Optional alone (it shows the user the vertex that are visited in the form of alphabets)
            }
        }
    }
}