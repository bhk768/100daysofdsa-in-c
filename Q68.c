/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological sort
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// Driver code
int main() {
    int V = 6;

    // Initialize adjacency list and visited
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Example DAG
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(V);

    return 0;
}