#include <iostream>
using namespace std;

int main(){
	int a = 15;
    int& c = a;
    c = a+1;
    cout<<a;

    /*
    *   Para empezar tuve que borrar el +1 del a, ya que, no era la forma correcta de sumarlo, si quisieramos sumarlo podríamos
    *   colocar un c = c + 1 o como está en el ejercicio c = a + 1, de estas dos maneras se puede sumar sin problemas
    */


}