#include <stdio.h>

int V;

void create(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void createNode(int src, int dest, int arr[][V]) {
    arr[src][dest] = 1;
}

void display(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of Vertices: ");
    scanf("%d", &V);
    
    int arr[V][V];
    create(arr);
    
    int i, j, hasEdge;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if(i!=j){
                printf("Enter 1 if there is an edge between nodes[%d %d] otherwise 0: ", i, j);
                scanf("%d", &hasEdge);
                if(hasEdge == 1){
                    createNode(i, j, arr);
                }
            }
        }
    }
    
    display(arr);
    return 0;
}