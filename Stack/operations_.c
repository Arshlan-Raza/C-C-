#include<stdio.h>
#include<stdlib.h>



struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *sp);
int isFull(struct stack *sp);

void push(struct stack *sp, int value){

    if(isFull(sp)){

        printf("Stack Overflow\n");

    }
    else{

        sp->top++;
        sp->arr[sp->top] = value;

    }
}

int pop(struct stack *sp){

    if(isEmpty(sp)){

        printf("Stack Underflow\n");
        return -1;

    }

    else{

        int value = sp->arr[sp->top];
        sp->top--;
        return value;

    }
}

int peek(struct stack *sp, int i){

    int arrInd = sp->top - i + 1;

    if(arrInd < 0){
        printf("Stack is Empty");
        return -1;
    }
    else{
        return sp->arr[arrInd];
    }
}

int isEmpty(struct stack *sp){
    if(sp->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *sp){
    if(sp->top == sp->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size*sizeof(int));
    push(sp, 2);
    push(sp, 3);
    push(sp, 2);
    push(sp, 3);
    // push(sp, 2);
    // push(sp, 3);
    // push(sp, 2);
    // push(sp, 3);
    // push(sp, 2);
    // push(sp, 3);
    printf("Pushed Successfully \n");
    printf("Elements are: \n");

    for(int i = 1; i <= sp->top + 1; i++){

        printf("%d ", peek(sp, i));
        printf(" ");
    }
    free(sp->arr);
    free(sp);
    return 0;

}
