#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree() {
    int val;
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->left = createTree();
    newNode->right = createTree();

    return newNode;
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int main() {
    struct Node* root = createTree();
    printf("%d", height(root));
    return 0;
}