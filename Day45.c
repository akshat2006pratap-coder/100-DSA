#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    if (data == -1) return NULL;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int height(struct node* root) {
    if (root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(n == 0 || arr[0] == -1) {
        printf("0");
        return 0;
    }

    struct node* root = createNode(arr[0]);

    struct node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while(i < n) {
        struct node* curr = queue[front++];

        if(arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    printf("%d", height(root));

    return 0;
}