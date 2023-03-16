#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[10] = {0};

    int *ptr = &arr[0];

    cout<<"Before : "<<ptr<<endl;
     
    ptr = ptr + 1;

    cout<<"After : "<<ptr<<endl;

    // Now we will see *ptr = *ptr + 1;

    *ptr = *ptr + 1;

    cout<<"The value is : "<<*ptr ;

}