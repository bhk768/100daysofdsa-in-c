/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index of value in inorder array
int search(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree recursively
struct TreeNode* buildTree(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Take current node from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;
    struct TreeNode* node = newNode(curr);

    // If node has no children
    if (inStart == inEnd)
        return node;

    // Find index of current node in inorder
    int inIndex = search(inorder, inStart, inEnd, curr);

    // Recursively build left and right subtrees
    node->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Print postorder traversal
void postOrder(struct TreeNode* root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

int main() {
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &preorder[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct TreeNode* root = buildTree(preorder, inorder, 0, N - 1, &preIndex);

    postOrder(root);
    printf("\n");

    return 0;
}