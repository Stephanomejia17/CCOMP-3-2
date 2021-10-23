#include <iostream>
using namespace std;
void A()
{
    cout << "A\n";
}
void B(void(*p)()) 
{
    p();
}
int main()
{
    void (*p)() = A;
    p(); //ejecutando la funcion A
    B(p); // Pasando A como parametro con puntero a funcion

}