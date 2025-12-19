#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int adj[MAX][MAX];
    int vertices;
} Graph;

void initGraph(Graph* g, int v) {
    int i, j;
    g->vertices = v;
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void DFSUtil(Graph* g, int v, int visited[]) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i = 0; i < g->vertices; i++) {
        if(g->adj[v][i] && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph* g, int start) {
    int visited[MAX] = {0};
    DFSUtil(g, start, visited);
    printf("\n");
}

void BFS(Graph* g, int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int i;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for(i = 0; i < g->vertices; i++) {
            if(g->adj[curr][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void display(Graph* g) {
    int i, j;
    for(i = 0; i < g->vertices; i++) {
        for(j = 0; j < g->vertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    initGraph(&g, 5);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);

    display(&g);
    DFS(&g, 0);
    BFS(&g, 0);

    return 0;
}

