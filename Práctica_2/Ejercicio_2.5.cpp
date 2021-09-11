#include <iostream>
using namespace std;

int main(){
    const double & a {1};
    const double & b {1}; //faltaba poner el const
    cout<<b <<"\n";

}