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

int searchBST(struct Node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

int main() {
    struct Node* root = createTree();
    int key;
    scanf("%d", &key);

    printf("%d", searchBST(root, key));
    return 0;
}