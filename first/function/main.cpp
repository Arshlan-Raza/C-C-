#include <iostream>
void say_hello();
void say_world();

using namespace std;


int main(){
    say_hello();
//    say_world();
    cout<<"Bye from main"<<endl;
    
}

void say_hello(){
    cout<<"Hello"<<" ";
    say_world();
    cout<< "Bye from say_hello"<<endl;
}

void say_world(){
//    say_hello();
    cout<<"World"<<endl;
    cout <<"Bye from say_world"<<endl;
    
}