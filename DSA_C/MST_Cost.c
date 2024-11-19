#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], tree[MAX][MAX], n;

int spanningtree(int src){
    int visited[MAX], d[MAX], parent[MAX];
    int i,j,k,min,u,v,cost;
    //Initialization
    for(i=1;i<=n;i++){
        d[i] = adj[src][i];//Distance of each node from the source is updated in d
        visited[i] = 0;//visited array is intialised to 0
        parent[i] = src;//initialising start vertex as the parent
    }
    visited[src] = 1;
    cost = 0;
    k = 1;
    //calculating the distance of each vertex
    for(i=1;i<n;i++){
        min = 9999;
        for(j=1;j<=n;j++){
            if(visited[j] == 0 && d[j] < min){
                min = d[j];
                u = j;
                cost += d[u];
            }
        }
        visited[u] = 1;
        tree[k][1] = parent[u];//updating the parent vertex as the first vertex of MST
        tree[k++][2] = u;//updating the remaining neighbour nodes of parent vertex into the MST
        for(v=1;v<=n;v++){
            if(visited[u] == 0; (adj[u][v] < d[v])){//selecting unvisited node and checking the distance b/w the source to destination distance
                d[v] = adj[u][v];//if minimum distance is found then updating the minimum distance
                parent[v] = u;//updating the destination vertex with this minimum path into the parent.
            }
        }
    }
    return cost;
}