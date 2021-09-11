#include <iostream>
using namespace std;

int main(){
    int vector[] = {4,5,6};
int* p1 = vector;
cout<<sizeof(p1);
cout<<sizeof(vector);
int* p2 = vector + 2;
cout<< p2 - p1;
p1 = p1 + p1;
cout<< p1 <<"\n";

}