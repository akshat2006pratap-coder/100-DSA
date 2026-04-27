#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == value)
            return i;
    return -1;
}

struct Node* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(postorder[(*postIndex)--]);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}