#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void init(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

int empty(Deque* dq) {
    return dq->size == 0;
}

int size(Deque* dq) {
    return dq->size;
}

void push_front(Deque* dq, int val) {
    if (dq->size == MAX) return;

    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = val;
    dq->size++;

    if (dq->size == 1)
        dq->rear = dq->front;
}

void push_back(Deque* dq, int val) {
    if (dq->size == MAX) return;

    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = val;
    dq->size++;

    if (dq->size == 1)
        dq->front = dq->rear;
}

void pop_front(Deque* dq) {
    if (empty(dq)) return;

    dq->front = (dq->front + 1) % MAX;
    dq->size--;
}

void pop_back(Deque* dq) {
    if (empty(dq)) return;

    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
}

int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

void reverse(Deque* dq) {
    int i = dq->front, j = dq->rear;
    int count = dq->size;

    while (count > 1) {
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
        count -= 2;
    }
}

void sort(Deque* dq) {
    for (int i = 0; i < dq->size - 1; i++) {
        for (int j = 0; j < dq->size - i - 1; j++) {
            int idx1 = (dq->front + j) % MAX;
            int idx2 = (dq->front + j + 1) % MAX;

            if (dq->arr[idx1] > dq->arr[idx2]) {
                int temp = dq->arr[idx1];
                dq->arr[idx1] = dq->arr[idx2];
                dq->arr[idx2] = temp;
            }
        }
    }
}

void display(Deque* dq) {
    if (empty(dq)) {
        printf("Empty\n");
        return;
    }

    for (int i = 0; i < dq->size; i++) {
        printf("%d ", dq->arr[(dq->front + i) % MAX]);
    }
    printf("\n");
}