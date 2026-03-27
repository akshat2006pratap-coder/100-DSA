#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* queue[100];
int front = 0, rear = -1;

void enqueue(struct node* n) {
    queue[++rear] = n;
}

struct node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void levelOrder(struct node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (!isEmpty()) {
        struct node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    levelOrder(root);

    return 0;
}