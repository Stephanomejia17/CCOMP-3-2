#include <iostream>
using namespace std;

int main(){
    int B[2][3]={7,1,8,
                2,3,5};
    int *p=*B;
    p=B[0];


    cout << B[0];
    cout << B[1][1];
}