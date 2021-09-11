#include <iostream>

using namespace std;

void recorre(char* A){
    char* p = A;
    for(p; *p; p++){
        cout << *p;
    }
}

int main(){
    char A[50] = {"Hello, world"};
    recorre(A);
}