#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

void display(struct queue* q){
    
    
    if((q->f == 0)||q->f>q->r){
            printf("Queue is Empty\n");
    }
    else{
            for(int i =  q->f;i<q->r;i++){
                printf("%d ",q->arr[i]);
            }
    }
}

int peek(struct queue *q, int index) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[index-1];
}

 
int main(){
    struct queue *q;
    q = (struct queue*) malloc (sizeof(struct queue));
    q->size = 10;
    q->f = q->r = 0;
    q->arr = (int*) malloc(q->size*sizeof(int));
    
    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1); 
    // printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q));
    // printf("Dequeuing element %d\n", dequeue(q)); 
    enqueue(q, 3);
    enqueue(q, 23);
    enqueue(q, 22);
 
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    if(isFull(q)){
        printf("Queue is full\n");
    }

    printf("\n");

    printf("\n Queue is : \n");
    display(q);

    printf("%d ",peek(q,2));
 
    return 0;
}
