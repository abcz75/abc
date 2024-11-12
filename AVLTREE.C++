#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node Structure
struct AVLNode {
    int key, height;
    struct AVLNode* left;
    struct AVLNode* right;
};

// Function to get the height of a node
int height(struct AVLNode* node) {
    return node ? node->height : 0;
}

// Function to update the height of a node
void updateHeight(struct AVLNode* node) {
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
}

// Right rotation
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotation
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Get balance factor of a node
int getBalance(struct AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Insert a node and balance the tree
struct AVLNode* insert(struct AVLNode* node, int key) {
    if (!node) {
        struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
        newNode->key = key;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // No duplicates allowed

    updateHeight(node);

    // Balance the tree
    int balance = getBalance(node);

    // Left-Left case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right-Right case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left-Right case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal to print the tree
void inorder(struct AVLNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct AVLNode* root = NULL;

    // Inserting nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 5);

    // Inorder traversal
    printf("Inorder traversal of the AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

