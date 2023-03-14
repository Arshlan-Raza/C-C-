#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

    string s;
    cout<<"Enter your string : ";
    getline(cin,s);

    string temp ="";

    // char nt = '@40';
    for(int i=0; i<s.length(); i++){
        int st = 0;
        if(s[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
            
        }
        else{
            temp.push_back(s[i]);
        }
        
         
        
    }

    cout<<temp;
}