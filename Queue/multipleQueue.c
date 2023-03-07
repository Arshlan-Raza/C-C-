#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of queues that can be created
#define MAX_QUEUES 10

// Define the struct for the multiple queue
struct MultipleQueue {
    int** arr;      // Pointer to an array of pointers to int
    int* front;     // Pointer to an array of front indices for each queue
    int* rear;      // Pointer to an array of rear indices for each queue
    int size;       // Size of each queue
    int count[MAX_QUEUES];  // Array of counts for each queue
    int n;          // Number of queues
};

// Function to create a multiple queue
struct MultipleQueue* createMultipleQueue(int n, int size) {

    // Allocate memory for the struct
    struct MultipleQueue* mq = (struct MultipleQueue*) malloc(sizeof(struct MultipleQueue));

    // Allocate memory for the array of pointers
    mq->arr = (int**) malloc(n * sizeof(int*));

    // Allocate memory for the front and rear arrays
    mq->front = (int*) malloc(n * sizeof(int));
    mq->rear = (int*) malloc(n * sizeof(int));

    // Set the size and number of queues
    mq->size = size;
    mq->n = n;

    // Loop through each queue and allocate memory for the array of integers and set initial values
    for (int i = 0; i < n; i++) {
        mq->arr[i] = (int*) malloc(size * sizeof(int));
        mq->front[i] = -1;
        mq->rear[i] = -1;
        mq->count[i] = 0;
    }

    // Return the created multiple queue
    return mq;
}

// Function to check if a queue is full
int isFull(struct MultipleQueue* mq, int queueIndex) {

    // A queue is full if its count is equal to its size
    return mq->count[queueIndex] == mq->size;
}

// Function to check if a queue is empty
int isEmpty(struct MultipleQueue* mq, int queueIndex) {
    
    // A queue is empty if its count is zero
    return mq->count[queueIndex] == 0;
}

// Function to enqueue a value to a queue
void enqueue(struct MultipleQueue* mq, int queueIndex, int val) {
    // Check if the queue is full
    if (isFull(mq, queueIndex)) {
        printf("Queue %d is full\n", queueIndex);
    } else {
        // If the queue is empty, set the front index to zero
        if (isEmpty(mq, queueIndex)) {
            mq->front[queueIndex] = 0;
        }
        // Increment the rear index and add the value to the array
        mq->rear[queueIndex] = (mq->rear[queueIndex] + 1) % mq->size;
        mq->arr[queueIndex][mq->rear[queueIndex]] = val;
        // Increment the count of the queue
        mq->count[queueIndex]++;
    }
}

// Function to dequeue a value from a queue
int dequeue(struct MultipleQueue* mq, int queueIndex) {
    // Check if the queue is empty
    if (isEmpty(mq, queueIndex)) {
        printf("Queue %d is empty\n", queueIndex);
        return -1;
    } else {
        // Get the value at the front index
        int val = mq->arr[queueIndex][mq->front[queueIndex]];
        // Increment the front index and decrement

    // the count of the queue
    mq->front[queueIndex] = (mq->front[queueIndex] + 1) % mq->size;
    mq->count[queueIndex]--;
    // If the queue is now empty, set the front and rear indices to -1
    if (isEmpty(mq, queueIndex)) {
    mq->front[queueIndex] = -1;
    mq->rear[queueIndex] = -1;
    }
    // Return the dequeued value
    return val;
    }
}

// Function to print the elements of a queue
void printQueue(struct MultipleQueue* mq, int queueIndex) {
// Check if the queue is empty
if (isEmpty(mq, queueIndex)) {
printf("Queue %d is empty\n", queueIndex);
} else {
// Loop through the queue and print each element
printf("Queue %d: ", queueIndex);
for (int i = mq->front[queueIndex]; i <= mq->rear[queueIndex]; i++) {
printf("%d ", mq->arr[queueIndex][i]);
}
printf("\n");
}
}

    int main() {
    // Create a multiple queue with 3 queues of size 5
    struct MultipleQueue* mq = createMultipleQueue(3, 5);

    // Enqueue some values to the queues
    enqueue(mq, 0, 1);
    enqueue(mq, 0, 2);
    enqueue(mq, 1, 3);
    enqueue(mq, 1, 4);
    enqueue(mq, 2, 5);
    enqueue(mq, 2, 6);

    // Print the queues
    printQueue(mq, 0);
    printQueue(mq, 1);
    printQueue(mq, 2);

    // Dequeue some values from the queues
    dequeue(mq, 0);
    dequeue(mq, 1);
    dequeue(mq, 2);

    // Print the queues again
    printQueue(mq, 0);
    printQueue(mq, 1);
    printQueue(mq, 2);

    return 0;
}