#include <stdio.h>
#define MAX 5

void breadth_first_search(int adj[][MAX], int visited[], int start) {
    int queue[MAX], front = -1, rear = -1, i;
    queue[++rear] = start;
    visited[start] = 1;

    while (rear != front) {
        start = queue[++front];
        if (start == 4) {
            printf("5\t");
        } else {
            printf("%c \t", start + 65);
        }
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void depth_first_search(int adj[][MAX], int visited[], int start) {
    int stack[MAX], top = -1, i;
    printf("%c- \t", start + 65);
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        start = stack[top];
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                printf("%c- \t", start + 65);
                visited[i] = 1;
                break;
            }
        }
        if (i == MAX) {
            top--;
        }
    }
}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX];
    int i, j;

    printf("\nEnter the adjacency matrix:");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d ", &adj[i][j]);
        }
    }

    printf("\nBreadth First Search:\n");
    breadth_first_search(adj, visited, 0);
    for (i = 0; i < MAX; i++) {
        visited[i] = 0; 
    }

    printf("\nDepth First Search:\n");
    depth_first_search(adj, visited, 0);
    printf("\n");

    return 0;
}
