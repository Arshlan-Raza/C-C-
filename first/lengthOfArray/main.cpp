#include <iostream>

using namespace std;

int main(){
    int a[5]{};
    int sizee = sizeof(a);
    int size2 = sizeof(a[0]);
    int len = sizee/size2;
    cout<<"The size of array is : "<< sizee<<endl;
    cout<<"The size of first element of array is : "<<size2<<endl;
    cout<<"The length of array is : "<<len<<endl;
}

