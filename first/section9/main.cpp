#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec;
    char choice;
    int number 
    
    cout<<"P-Print Numbers"<<endl;
    cout<<"A-Add a number"<<endl;
    cout<<"M-Display mean of the numbers"<<endl;
    cout<<"S-Display the smallest number"<<endl;
    cout<<"L-Display the largest number"<<endl;
    cout<<"Q-Quit"<<endl;
    
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    
    if(choice=='P'&&choice=='p'){
        for(int i=0;i<vec.size();++i)
            cout<<"vec(i)";
    }
    else if (choice=='a'&& choice=='A'){
        cout<<"Enter the number to add"<<endl;
        cin>>number;
        vec.pushback(number); 
    }
    return 0;
}