#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *queue;
    int front, rear, size;
} CircularQueue;

CircularQueue* CreateQueue(int size) {
    CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
    cq->size = size;
    cq->front = -1;
    cq->rear = -1;
    cq->queue = (int*)malloc(cq->size * sizeof(int));
    return cq;
}

int isEmpty(CircularQueue* cq) {
    return (cq->front == -1);
}

int isFull(CircularQueue* cq) {
    return ((cq->rear + 1) % cq->size == cq->front);
}

CircularQueue* Enqueue(CircularQueue* cq, int data) {
    if (isFull(cq)) {
        printf("Queue is full\n");
        return cq;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % cq->size;
    cq->queue[cq->rear] = data;
    return cq;
}

CircularQueue* Dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return cq;
    }
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % cq->size;
    }
    return cq;
}

int Peek(CircularQueue* cq) {
    if (isEmpty(cq)) {
        return INT_MIN;
    }
    return cq->queue[cq->front];
}

void Print(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    int index = cq->front;
    while (index != cq->rear) {
        printf("%d ", cq->queue[index]);
        index = (index + 1) % cq->size;
    }
    printf("%d\n", cq->queue[index]);
}

int main() {
    CircularQueue* cq = CreateQueue(5);
    Enqueue(cq, 1);
    Enqueue(cq, 2);
    Enqueue(cq, 3);
    Enqueue(cq, 4);
    Enqueue(cq, 5);
    Print(cq);
    Dequeue(cq);
    Print(cq);
    Enqueue(cq, 6);
    Print(cq);
    return 0;
}