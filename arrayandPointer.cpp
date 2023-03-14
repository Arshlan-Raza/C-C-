#include<bits/stdc++.h>

using namespace std;

int main(){

    int a[6] = {1, 2, 3, 4, 5};
    int *ptr = &a[0];

    cout<<"Size of - for a : "<<sizeof(a)<<endl;
    cout<<"Size of - for &a : "<<sizeof(&a)<<endl;
    cout<<"Size of - for *ptr : "<<sizeof(*ptr)<<endl;
    cout<<"Size of - for ptr : "<<sizeof(ptr)<<endl;
    cout<<"Size of - for &ptr : "<<sizeof(&ptr)<<endl;

    for(int i = 0;i<6;i++){
        cout<<*(ptr + i)<<" ";
    }
}