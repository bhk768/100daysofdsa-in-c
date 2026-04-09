/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void topologicalSort(int n) {
    int i, j, count = 0;

    // Compute indegree of each vertex
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Enqueue all vertices with indegree 0
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order: ");

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of adjacent vertices
        for(j = 0; j < n; j++) {
            if(adj[node][j] == 1) {
                indegree[j]--;
                if(indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    // Check for cycle
    if(count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int n, m, i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency matrix
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) for directed graph:\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(n);

    return 0;
}