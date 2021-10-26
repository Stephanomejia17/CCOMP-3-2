#include <iostream>

using namespace std;

void Eliminar(char* texto,char* q)
{
  while(*q){
    *q = *(q+1);
    q++;
  }
}

void ExtraerInverso(char* texto, int tam, char* secuencia)
{
  for (char* p=texto+tam; p>=texto; p--)
  {

    if (*p == *secuencia)
     {
       secuencia++;
       Eliminar(texto,p);
     } 
  }
}

int main() {
	
	char prueba[100]="Buenos dias amigos";
  char secuencia[100]="sasone";

	cout << prueba<<endl;
	ExtraerInverso(prueba, 18 ,secuencia);
	cout << prueba << endl;
	
	return 0;
}