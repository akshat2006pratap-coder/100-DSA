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

struct Node* build(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(preorder[(*preIndex)++]);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->left = build(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}