/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];

// function to add edge
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function to detect cycle
bool dfs(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    Node* temp = adj[v];
    while (temp != NULL) {
        int neigh = temp->vertex;

        if (!visited[neigh]) {
            if (dfs(neigh, visited, recStack))
                return true;
        } 
        else if (recStack[neigh]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = false;
    return false;
}

// function to check cycle
bool hasCycle(int V) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v); // directed graph
    }

    if (hasCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}