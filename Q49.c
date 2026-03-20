/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return 1;  // leaf node
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Inorder traversal (for checking tree structure)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Example tree:
    //        10
    //       /  \
    //      20   30
    //     / \     \
    //    40 50     60
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->right = createNode(60);

    printf("Inorder Traversal of Tree: ");
    inorder(root);
    printf("\n");

    int leafCount = countLeafNodes(root);
    printf("Number of Leaf Nodes = %d\n", leafCount);

    return 0;
}