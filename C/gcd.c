#include<stdio.h>

int gcd(int n1 , int n2){
    
    if(n2!=0){
        return gcd(n1,n1%n2);
    }
    else{
        return n1;
    }
}

int main(){

    int n1 , n2;

    printf("Enter the n1 and n2\n");

    scanf("%d %d",&n1,&n2);

    printf("The gcd of two number is %d",gcd(n1,n2));
}