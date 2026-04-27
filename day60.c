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

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[MAX];
    for (int i = 0; i < n; i++)
        nodes[i] = newNode(arr[i]);

    for (int i = 0; i < n; i++) {
        if (2*i + 1 < n)
            nodes[i]->left = nodes[2*i + 1];
        if (2*i + 2 < n)
            nodes[i]->right = nodes[2*i + 2];
    }

    return nodes[0];
}

int isComplete(int index, int n) {
    if (index >= n) return 0;
    return 1;
}

int isMinHeap(struct Node* root) {
    if (!root) return 1;

    if (root->left && root->left->data < root->data) return 0;
    if (root->right && root->right->data < root->data) return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}