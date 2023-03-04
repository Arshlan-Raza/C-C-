#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left ;
    struct node* right;
};

int  isBST(struct node* p){

    static struct node* prev = NULL;

    if(p!=NULL){

        if(!isBST(p->left)){
            return 0;
        }
        if(prev!=NULL && p->data <= prev->data){
            return 0;
        }

        prev = p;
        return isBST(p->right);
    }

    return 1;
}

int check(int *arr){
    int i =0,j= 15;
    for(i = 0; i < 15; i++){
        for(j = i + 1; j < 15; j++){
            if(arr[i] > arr[j])
                return 0;
        }
    }
    return 1;
}

struct node* create_node(int data){
    struct node* p = (struct node* ) malloc (sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main(){
    struct node* p = create_node(9);
    struct node* p1 = create_node(4);
    struct node* p2 = create_node(11);
    struct node* p3 = create_node(2);
    struct node* p4 = create_node(7);
    struct node* p5 = create_node(15);
    struct node* p6 = create_node(5);
    struct node* p7 = create_node(8);
    struct node* p8 = create_node(14);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = NULL;
    p2->right = p5;

    p3->left = NULL;
    p3->right = NULL;

    p4->left = p6;
    p4->right = p7;

    p5->left = p8;
    p5->right = NULL;

    // int arr[15] = {};
    // is(p, arr);
    
    int ans = isBST(p);

    if(ans){
        printf("It is a BST \n");
    }
    else{
        printf("It is not a BST \n");
    }

   
    
    return 0;
}
