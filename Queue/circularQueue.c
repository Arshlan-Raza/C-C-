#include<stdio.h>
#include<stdlib.h>
 
struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}
void display(struct circularQueue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i;
        q->f = (q->f +1)%q->size;
        q->r = (q->r +1)%q->size;
        for(i = q->f; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int peek(struct circularQueue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->f];
}
 
int main(){
    struct circularQueue *q;

    q = (struct circularQueue*) malloc (sizeof(struct circularQueue));

    q->size = 10;
    q->f = q->r = 0;
    q->arr = (int*) malloc(q->size*sizeof(int));
    
    // Enqueue few elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3); 
    // printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q)); 
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
 
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    if(isFull(q)){
        printf("Queue is full\n");
    }

    printf("\n");
    display(q);
    printf("\n");

    printf("Peeking...%d ",peek(q));
 
    return 0;
}
