#include <iostream>
#include <string>
using namespace std;

int main(){
    string str{};
    cout<<"Insert the string you want to make pyramid of:";
    getline(cin,str);
    int length=str.length();
    for(int i=0;i<length-1;++i){
        cout<<str.at(i);
        for(int j=0;j<(i+1);++i){
            cout<<str.at(i);
        
            for(int i=(length-1);i<=0;--i){
                cout<<str.at(i)<<endl;
            }
        }
    }
   
    
    return 0;
}