#include<iostream>
#include <string>
using namespace std;

int main(void){
    
    string name;
    
    for(int i = 0; i < 3; i++){
        cout << "What is your name? ";
        getline (cin, name);
        
        cout << "Hello, " << name << "!\n";
        cout << endl;
    }
}