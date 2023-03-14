#include<bits/stdc++.h>

using namespace std;

int main(){

    int n , m ;

    cout<<"Enter the value of row and column : ";
    cin>>n>>m;

    int** arr = new int* [n];

    for(int i = 0; i<n; i++){

        arr[i] = new int [m];
    }

    cout<<"Enter the array elements : ";

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
                cin>>arr[i][j];
        }
    }

    cout<<"Printing the array elements : "<<endl;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = 0 ; i<n; i++){
        delete []arr[i];
    }
    delete []arr;

    cout<<"Memory freed successfully ------>>>>>"<<endl;
}