#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    if (front == NULL) {
        front = rear = temp;
        temp->next = temp;
    } else {
        temp->next = front;
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) return;
    if (front == rear) {
        free(front);
        front = rear = NULL;
        return;
    }
    struct Node* temp = front;
    front = front->next;
    rear->next = front;
    free(temp);
}

void display() {
    if (front == NULL) return;
    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int val = front->data;
        dequeue();
        enqueue(val);
    }
    display();
    return 0;
}