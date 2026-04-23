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

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;

    node->left = createTree();
    node->right = createTree();

    return node;
}

int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    struct Node* root = createTree();
    printf("%d", countLeaves(root));
    return 0;
}