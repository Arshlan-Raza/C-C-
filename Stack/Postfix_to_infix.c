#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

char* postfixToPrefix(char* postfix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * prefix = (char *) malloc((strlen(postfix)+1) * sizeof(char));
    int i=0; // Track postfix traversal
    int j = 0; // Track prefix addition 
    while (postfix[i]!='\0')
    {
        if(!isOperator(postfix[i])){
            push(sp, postfix[i]);
            i++;
        }
        else{
            char op1 = pop(sp);
            char op2 = pop(sp);
            prefix[j] = postfix[i];
            j++;
            prefix[j] = op2;
            j++;
            prefix[j] = op1;
            j++;
            i++;
        }
    }
    while (!isEmpty(sp))    
    {
        prefix[j] = pop(sp);
        j++;
    }
    prefix[j] = '\0';
    return strrev(prefix); // reverse the prefix string
}

int main()
{
    char * postfix = "xyz/-kd*+";
    printf("prefix is %s", postfixToPrefix(postfix));
    return 0;
}
