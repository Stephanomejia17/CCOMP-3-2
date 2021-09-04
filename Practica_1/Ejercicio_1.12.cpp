#include <iostream>
using namespace std;

int main(){
	int a = 15; //direcci´on asignada 300
    int*p = &a; //direcci´on asignada 304
    cout << p << endl;
    cout << *(&p)<< endl;
    cout << &(*p)<< endl;


}