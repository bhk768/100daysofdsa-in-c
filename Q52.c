/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>

// Definition of BST node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct TreeNode* LCA(struct TreeNode* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If both values are smaller → go left
    if (n1 < root->val && n2 < root->val)
        return LCA(root->left, n1, n2);

    // If both values are greater → go right
    if (n1 > root->val && n2 > root->val)
        return LCA(root->right, n1, n2);

    // Otherwise, this is the LCA
    return root;
}

int main() {
    int n, val, n1, n2;
    struct TreeNode* root = NULL;

    // Input
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &n1, &n2);

    struct TreeNode* result = LCA(root, n1, n2);

    if (result != NULL)
        printf("%d\n", result->val);

    return 0;
}