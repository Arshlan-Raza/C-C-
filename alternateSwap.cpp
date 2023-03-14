#include<iostream>

using namespace std; 

void swapAleter(int arr[] , int n ){

    int temp ;

    for (int i = 0 ; i<n ; i+=2){
       
       if(i+1<n)
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        
    }
}

void print(int arr[] , int n ){

    for (int i = 0 ; i<n ; i++){

        cout<<arr[i]<<" ";
    }
}

int main(){

    int size ; 

    cout<<"Enter the size of array : ";

    cin>>size;

    int num[100];

    for(int i = 0 ; i<size ; i++){

        cin>>num[i];
    }

    cout<<"Array before swapping : "<<endl;
    print(num , size );

    swapAleter(num,size);

     cout<<"\nArray after swapping : "<<endl;
    print(num , size );

}