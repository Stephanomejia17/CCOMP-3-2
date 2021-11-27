#include <iostream>
using namespace std;

void imprimir(char *m, int dim1)
{    
    char *p= m;
    char *q= m;
    while (p< (m)+(dim1*dim1))
    {
        while (p< q+(dim1))
        {   
            cout<<*p<<" ";
            p++;
        }
        cout<<endl;
        q = q+dim1;
    }
}
void insertar(char* m, int pos_F, int pos_C, int dim,int* ptr_ju){   
    char* p = m; 
    if(*ptr_ju == 1){
        p += (dim*(pos_F))+(pos_C);
        *p = 'X';
    }
    else{
        p += (dim*(pos_F))+(pos_C);
        *p = 'O';
    }

}
void verificador(char* ptr_array, int dim, int* ptr_jugadores, int N,bool &f){
    int A = 1;
    int B = 0;
    int C = N/2;
    char simbolo = (*ptr_jugadores/2==0) ? 'O' : 'X';
    for(; A <= dim/2;){
      if(*(ptr_array+dim) == simbolo){
        A += 1;
        ptr_array = ptr_array+dim;
      }
      else{
        break;
      }
    }
    cout << A << endl;
    /*for(; B <= N/2;){
      for(int i = 1; i <= C; i++){
        if(*(ptr_array+i) == simbolo){
          B++;
        }
        else{
          break;
        }
      }
      for(int i = 1; i <= C; i++){
        if(*(ptr_array-i) == simbolo){
          B++;
        }
        else{
          break;
        }
      }
    }*/

    
    if(A==dim/2){f=false;}
    
}
void datos(int* ptr_jugadores, int& pos_F, int& pos_C, int dim){
  printf("Jugador %d ingrese la posicion en FILAS: ",*ptr_jugadores); cin >> pos_F;
        printf("Jugador %d ingrese la posicion en COLUMNAS: ",*ptr_jugadores); cin >> pos_C;
        if(pos_F >= dim){
            printf("Ingrese una posicion valida de Filas: "); cin >> pos_F;
        }
        if(pos_C >= dim){
            printf("Ingrese una posicion valida de Columnas: "); cin >> pos_C;
        }
}
void alternador(int& jugadores){
  if(jugadores == 1){jugadores++;}
  else{jugadores--;}
}
void dimYn(int& dim, int& N){
  cout << "Ingrese el tamanio del tablero: "; cin >>dim;
  cout << "Ingrese un numero impar: "; cin >> N;
}

int main(){
    int dim;
    char i = '=';
    int jugadores[2] = {1,2};
    int pos_F;
    int pos_C;
    int* ptr_jugadores = jugadores;
    int N;
    bool Comp = true;
    dimYn(dim, N);
    //char array[dim][dim];
    char* array1 = new char[dim*dim];
    char* ptr_array= array1;
    char* ptr2_array = ptr_array;
    char a = 254;
    for(; ptr2_array < ptr_array+(dim*dim); ptr2_array++){
        *ptr2_array = a;
    }
    cout << " JUEGO N EN L " << endl;
    
    imprimir(ptr_array, dim);
    while(Comp){
        
        datos(ptr_jugadores, pos_F, pos_C, dim);
        insertar(ptr_array, pos_F, pos_C, dim, ptr_jugadores);
        verificador(ptr2_array, dim, ptr_jugadores,N,Comp);
        imprimir(ptr_array, dim);
        alternador(*ptr_jugadores);
        
        
    }
    cout << "Ganaste!";
    

    return 0;
}