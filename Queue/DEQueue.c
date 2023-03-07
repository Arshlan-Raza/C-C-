#include <stdio.h>
#include <stdlib.h>

struct deque {
    int size;
    int f; // front index
    int r; // rear index
    int* arr;
};

int isEmpty(struct deque* q) {
    if (q->f == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct deque* q) {
    if (q->r == q->size - 1) {
        return 1;
    }
    return 0;
}

void enqueueFront(struct deque* q, int val) {

    if (isFull(q)) {
        printf("Deque is full\n");
    } else {
        if (q->f == -1) { // If deque is initially empty
            q->f = q->r = 0;
            q->arr[q->f] = val;
        } else if (q->f != 0) {
            q->f--;
            q->arr[q->f] = val;
        } else {
            printf("Cannot enqueue at front, deque is full\n");
        }
        printf("Enqueued element %d at front\n", val);
    }
}

void enqueueRear(struct deque* q, int val) {

    if (isFull(q)) {
        printf("Deque is full\n");
    } else {
        if (q->f == -1) { // If deque is initially empty
            q->f = q->r = 0;
            q->arr[q->r] = val;
        } else {
            q->r++;
            q->arr[q->r] = val;
        }
        printf("Enqueued element %d at rear\n", val);
    }
}

int dequeueFront(struct deque* q) {

    int a = -1;
    if (isEmpty(q)) {
        printf("Deque is empty\n");
    } else {
        a = q->arr[q->f];
        if (q->f == q->r) { // If deque has only one element
            q->f = q->r = -1;
        } else {
            q->f++;
        }
    }
    return a;
}

int dequeueRear(struct deque* q) {

    int a = -1;
    if (isEmpty(q)) {
        printf("Deque is empty\n");
    } else {
        a = q->arr[q->r];
        if (q->f == q->r) { // If deque has only one element
            q->f = q->r = -1;
        } else {
            q->r--;
        }
    }
    return a;
}

void display(struct deque* q) {

    if (isEmpty(q)) {
        printf("Deque is empty\n");
    } else {
        for (int i = q->f; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int peekFront(struct deque* q) {

    if (isEmpty(q)) {
        printf("Deque is empty\n");
        return -1;
    }
    return q->arr[q->f];
}

int peekRear(struct deque* q) {
    
    if (isEmpty(q)) {
        printf("Deque is empty\n");
        return -1;
    }
    return q->arr[q->r];
}

int main() {
    struct deque* q;
    q = (struct deque*)malloc(sizeof(struct deque));
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    // Enqueue elements
enqueueRear(q, 10);
enqueueRear(q, 20);
enqueueFront(q, 30);
enqueueFront(q, 40);

// Display the deque
printf("Deque: ");
display(q);

// Dequeue elements
printf("Dequeued element from front: %d\n", dequeueFront(q));
printf("Dequeued element from rear: %d\n", dequeueRear(q));

// Display the deque
printf("Deque: ");
display(q);

// Peek front and rear
printf("Front element: %d\n", peekFront(q));
printf("Rear element: %d\n", peekRear(q));

// Enqueue at front when deque is full
enqueueFront(q, 50);

// Display the deque
printf("Deque: ");
display(q);

// Enqueue at rear when deque is full
enqueueRear(q, 60);

// Display the deque
printf("Deque: ");
display(q);

// Free allocated memory
free(q->arr);
free(q);

return 0;
}