#include <iostream>
using namespace std;
int aumentar(int a)
{
    return ++a;
}
int main()
{
    int c;
    int (*p) (int);
    p = aumentar;
    c = p(4);
    cout << c << "\n";
}