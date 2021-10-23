//Cree una funcion llama "TRIM" que elimine los espacios de un texto
// Ej. "Christian Delgado Polar" -> "ChristianDelgadoPolar"
// todo con punteros, sin indices. Utilizando array de caracteres


#include <iostream>
using namespace std;
void TRIM(char oracion[], int tamanio){
  char *ptr = oracion;
  char final [tamanio];
  char *ptrFinal = final;
  int tamFinal=sizeof(final)/sizeof(final[0]); 
    //asignacion de valores
  for(;ptr < oracion + tamanio ;){
    if(*ptr == ' '){
      ptr++;
      continue;
    }
    else{
      *ptrFinal = *ptr;
      ptr++;
      ptrFinal++;
    }
  }
  ptrFinal = final;
    //imprimimos valores
  for(; ptrFinal < final + tamFinal; ptrFinal++ ){
      if(*ptrFinal == '\0'){break;}
      else{cout << *ptrFinal;}
  }
}
int main(){
  char oracion [] = "Walter Stephano Mejia Morales";
  int tamanio = sizeof(oracion)/sizeof(oracion[0]);
  TRIM(oracion, tamanio);
  return 0;
}
