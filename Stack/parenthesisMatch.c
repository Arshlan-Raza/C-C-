#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *sp);
int isFull(struct stack *sp);

void push(struct stack *sp, char value){

    if(isFull(sp)){

        printf("Stack Overflow\n");

    }
    else{

        sp->top++;
        sp->arr[sp->top] = value;

    }
}

char pop(struct stack *sp){

    if(isEmpty(sp)){

        // printf("Stack Underflow\n");
        return -1;

    }

    else{

        char value = sp->arr[sp->top];
        sp->top--;
        return value;

    }
}

int parenthesisMatch(char *arr){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    int count = strlen(arr);
    sp->size = count;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    for(int i = 0; arr[i]!='\0'; i++){
        if(arr[i] == '('){
            push(sp,arr[i]);
        }
        else{
            if(isEmpty(sp)){
                free(sp->arr);
                free(sp);
                return 0;
            }
            else{
               pop(sp);
            }
        }
    }
    if(isEmpty(sp)){
        free(sp->arr);
        free(sp);
        return 1;
    }
    else{
        return 0;
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
    char arr[100];
    printf("Enter the expression :");
    gets(arr);
    int ans = parenthesisMatch(arr);

    if(ans){
        printf("Matched\n");
    }
    else{
        printf("Unmatched\n");
    }
   
    return 0;

}
