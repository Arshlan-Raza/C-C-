#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 10

struct MultipleQueue {
    int** arr;
    int* front;
    int* rear;
    int size;
    int count[MAX_QUEUES];
    int n;
};

struct MultipleQueue* createMultipleQueue(int n, int size) {

    struct MultipleQueue* mq = (struct MultipleQueue*) malloc(sizeof(struct MultipleQueue));

    mq->arr = (int**) malloc(n * sizeof(int*));
    mq->front = (int*) malloc(n * sizeof(int));
    mq->rear = (int*) malloc(n * sizeof(int));
    mq->size = size;
    mq->n = n;

    for (int i = 0; i < n; i++) {
        mq->arr[i] = (int*) malloc(size * sizeof(int));
        mq->front[i] = -1;
        mq->rear[i] = -1;
        mq->count[i] = 0;
    }

    return mq;
}

int isFull(struct MultipleQueue* mq, int queueIndex) {

    return mq->count[queueIndex] == mq->size;
}

int isEmpty(struct MultipleQueue* mq, int queueIndex) {
    
    return mq->count[queueIndex] == 0;
}

void enqueue(struct MultipleQueue* mq, int queueIndex, int val) {
    if (isFull(mq, queueIndex)) {
        printf("Queue %d is full\n", queueIndex);
    } else {
        if (isEmpty(mq, queueIndex)) {
            mq->front[queueIndex] = 0;
        }
        mq->rear[queueIndex] = (mq->rear[queueIndex] + 1) % mq->size;
        mq->arr[queueIndex][mq->rear[queueIndex]] = val;
        mq->count[queueIndex]++;
    }
}

int dequeue(struct MultipleQueue* mq, int queueIndex) {
    if (isEmpty(mq, queueIndex)) {
        printf("Queue %d is empty\n", queueIndex);
        return -1;
    } else {
        int val = mq->arr[queueIndex][mq->front[queueIndex]];
        mq->front[queueIndex] = (mq->front[queueIndex] + 1) % mq->size;
        mq->count[queueIndex]--;
        if (isEmpty(mq, queueIndex)) {
            mq->front[queueIndex] = -1;
            mq->rear[queueIndex] = -1;
        }
        return val;
    }
}

void display(struct MultipleQueue* mq, int queueIndex) {
    if (isEmpty(mq, queueIndex)) {
        printf("Queue %d is empty\n", queueIndex);
    } else {
        printf("Queue %d: ", queueIndex);
        int i = mq->front[queueIndex];
        while (i != mq->rear[queueIndex]) {
            printf("%d ", mq->arr[queueIndex][i]);
            i = (i + 1) % mq->size;
        }
        printf("%d\n", mq->arr[queueIndex][i]);
    }
}

int main() {
    int n = 2; // Number of queues
    int size = 5; // Capacity of each queue

    struct MultipleQueue* mq = createMultipleQueue(n, size);

    // Enqueue elements
    
    enqueue(mq, 0, 20);
    enqueue(mq, 0, 30);
    enqueue(mq, 0, 40);
    enqueue(mq, 0, 50);
    enqueue(mq, 1, 100);
    enqueue(mq, 1, 200);
    enqueue(mq, 1, 300);
    enqueue(mq, 1, 400);
    // enqueue(mq, 2, 1000);
    // enqueue(mq, 2, 2000);
   // Display queues
    display(mq, 0);
    display(mq, 1);
    // display(mq, 2);

    // Dequeue elements
    printf("Dequeued value from Queue 0: %d\n", dequeue(mq, 0));
    printf("Dequeued value from Queue 1: %d\n", dequeue(mq, 1));
    // printf("Dequeued value from Queue 2: %d\n", dequeue(mq, 2));
    printf("Dequeued value from Queue 0: %d\n", dequeue(mq, 0));
    printf("Dequeued value from Queue 1: %d\n", dequeue(mq, 1));
    // printf("Dequeued value from Queue 2: %d\n", dequeue(mq, 2));

    // Display queues after dequeue
    display(mq, 0);
    display(mq, 1);
    // display(mq, 2);

    return 0;
}