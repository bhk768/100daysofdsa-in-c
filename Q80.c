/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, w;
} Node;

typedef struct {
    Node data[MAX];
    int size;
} MinHeap;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *h, int v, int w) {
    int i = h->size++;
    h->data[i].v = v;
    h->data[i].w = w;

    while (i > 0 && h->data[(i - 1) / 2].w > h->data[i].w) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop(MinHeap *h) {
    Node root = h->data[0];
    h->data[0] = h->data[--h->size];

    int i = 0;
    while (2 * i + 1 < h->size) {
        int smallest = 2 * i + 1;
        if (2 * i + 2 < h->size && h->data[2 * i + 2].w < h->data[smallest].w)
            smallest = 2 * i + 2;

        if (h->data[i].w <= h->data[smallest].w) break;

        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }

    return root;
}

int isEmpty(MinHeap *h) {
    return h->size == 0;
}

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* newNode = (Edge*)malloc(sizeof(Edge));
    newNode->to = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // remove if directed
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    MinHeap heap;
    heap.size = 0;

    dist[source] = 0;
    push(&heap, source, 0);

    while (!isEmpty(&heap)) {
        Node curr = pop(&heap);
        int u = curr.v;
        int d = curr.w;

        if (d > dist[u]) continue;

        Edge* temp = adj[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}