#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue {
    int* arr;
    int size;
    int count;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct PriorityQueue* q, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < q->count && q->arr[left] > q->arr[largest]) {
        largest = left;
    }

    if (right < q->count && q->arr[right] > q->arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&q->arr[i], &q->arr[largest]);
        maxHeapify(q, largest);
    }
}

void buildMaxHeap(struct PriorityQueue* q) {
    int i;
    for (i = (q->count - 1) / 2; i >= 0; i--) {
        maxHeapify(q, i);
    }
}

struct PriorityQueue* createPriorityQueue(int size) {
    struct PriorityQueue* q = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->size = size;
    q->count = 0;
    return q;
}

int isEmpty(struct PriorityQueue* q) {
    return q->count == 0;
}

int isFull(struct PriorityQueue* q) {
    return q->count == q->size;
}

int peek(struct PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    return q->arr[0];
}

void enqueue(struct PriorityQueue* q, int val) {
    if (isFull(q)) {
        printf("Priority queue is full\n");
    } else {
        q->count++;
        int i = q->count - 1;
        q->arr[i] = val;

        while (i != 0 && q->arr[(i-1)/2] < q->arr[i]) {
            swap(&q->arr[i], &q->arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }
}

int dequeue(struct PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Priority queue is empty\n");
        return -1;
    }

    int root = q->arr[0];
    q->arr[0] = q->arr[q->count-1];
    q->count--;
    maxHeapify(q, 0);
    return root;
}

void display(struct PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Priority queue is empty\n");
    } else {
        for (int i = 0; i < q->count; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct PriorityQueue* q = createPriorityQueue(5);

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Display the priority queue
    printf("Priority queue: ");
    display(q);

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));

    // Display
    // Display
printf("Priority queue after dequeuing elements: ");
display(q);

// Enqueue more elements
enqueue(q, 5);
enqueue(q, 15);

// Display
printf("Priority queue after enqueuing elements: ");
display(q);

// Peek
printf("Peek: %d\n", peek(q));

// Dequeue all elements
while (!isEmpty(q)) {
    printf("Dequeued element: %d\n", dequeue(q));
}

// Display
printf("Priority queue after dequeuing all elements: ");
display(q);

// Enqueue an element
enqueue(q, 25);

// Display
printf("Priority queue after enqueuing one element: ");
display(q);

// Free memory
free(q->arr);
free(q);

return 0;
}