/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];  // hash table
int m;           // table size

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using Quadratic Probing
void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using Quadratic Probing
void search(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[newIndex] == EMPTY) {
            break;  // key not present
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);   // size of hash table
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}