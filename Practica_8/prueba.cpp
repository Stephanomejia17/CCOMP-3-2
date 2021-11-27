#include <iostream>

using namespace std;
void imprimir(int* matriz, int n){
  int* p=matriz;
  //
  cout<<"  ";
  for(int i=1;i<=n;i++) cout<<i<<" ";
  cout<<endl;
  //

  for(int i=0;i<n;i++){
    cout<<"  _____"<<endl;
    cout<<i+1<<' ';
    for(int j=0;j<n;j++){
      cout<<'|';
      switch(*p) {
        case 0:
          cout<<"O";
          break;
        case 1:
          cout<<"X";
          break;
        case 2:
          cout<<' ';
          break;

      }
      p++;
      
    }
    cout<<"|"<<endl;
  }
  cout<<"  _____"<<endl;
  

}

void colocar_fichas(int* m,int dim,bool instruccion){
  int x,y;
  char a;
  if(instruccion){
    cout<<"TURNO DE LAS X: "<<endl;
    a='X';
  }
  else{
    cout<<"TURNO DE  LAS O: "<<endl;
    a='O';
  }
  cout<<"Posicion en x: ";cin>>x;
  cout<<"Posicion en y: ";cin>>y;

  int* pointer=m;
  pointer+=(y-1)*(dim);
  pointer+=(x-1);
  switch(a) {
    case 'O':
      *pointer=0;
      break;
    case 'X':
      *pointer=1;
      break;
  }
  cout<<endl;
  imprimir(m,dim);
}

void buscar_n_n_l(int n,int* p,int suma_piso,int suma_techo,int c,bool& buscador){
  if(*p==c){
    int i=0;
    int* ptr_piso=p;
    int* ptr_techo=p;
    for(i=0;i<n/2;i++){
      ptr_piso+=suma_piso;
      ptr_techo+=suma_techo;
      if(*ptr_piso!=c||*ptr_techo!=c){
        buscador=false;
        break;
      }
    }
    if(i==n/2){
      buscador=true;
    }
  }
  else{
    buscador=false;
  }
  
}






void verificar_n_n_l(int*  matriz,int dim,bool& run,int n){
  int* pointer=matriz;
  int* q=matriz;
  bool buscador_0(false);
  bool buscador_X(false);

  int cont(0);

  while((pointer<matriz+dim*dim)&&(buscador_0!=true||buscador_X!=true)){
    
    //REDONDAS
    buscar_n_n_l(n,pointer,1,dim,0,buscador_0);//ESTE Y SUR
    if(buscador_0){
      cout<<endl<<"Tenemos un ganador en las REDONDAS"<<endl;
      run=false;
      break;
    } 
    buscar_n_n_l(n,pointer,-1,dim,0,buscador_0);//OESTE Y SUR
    if(buscador_0){
      cout<<endl<<"Tenemos un ganador en las REDONDAS"<<endl;
      run=false;
      break;
    } 
    buscar_n_n_l(n,pointer,1,-dim,0,buscador_0);//NORTE Y ESTE
    if(buscador_0){
      cout<<endl<<"Tenemos un ganador en las REDONDAS"<<endl;
      run=false;
      break;
    } 
    buscar_n_n_l(n,pointer,-1,-dim,0,buscador_0);//NORTE Y OESTE
    if(buscador_0){
      cout<<endl<<"Tenemos un ganador en las REDONDAS"<<endl;
      run=false;
      break;
    } 

    //cruz
    buscar_n_n_l(n,pointer,1,dim,1,buscador_X);//ESTE Y SUr
    if(buscador_X){
      cout<<endl<<"Tenemos un ganador en las CRUZES"<<endl;
      run=false;
      break;
    } 
    buscar_n_n_l(n,pointer,-1,dim,1,buscador_X);//OESTE Y SUR
    if(buscador_X){
      cout<<endl<<"Tenemos un ganador en las CRUZES"<<endl;
      run=false;
      break;
    }
    buscar_n_n_l(n,pointer,1,-dim,1,buscador_X);//NORTE Y ESTE
    if(buscador_X){
      cout<<endl<<"Tenemos un ganador en las CRUZES"<<endl;
      run=false;
      break;
    }
    buscar_n_n_l(n,pointer,-1,-dim,1,buscador_X);//NORTE Y OESTE
    if(buscador_X){
      cout<<endl<<"Tenemos un ganador en las CRUZES"<<endl;
      run=false;
      break;
    }

    pointer++;



  }

}

void Jugar(int* matriz,int dim,int n){
  bool run(1);
  bool instruccion(0);

  while(run){
    colocar_fichas(matriz,dim,instruccion);
    instruccion= not instruccion;
    verificar_n_n_l(matriz,dim,run,n);
  }

}
int main(){
  int matriz[6][6]{{1,1,1,2,2,2},{2,2,1,2,2,2},{2,2,1,2,2,2},{2,2,2,2,2,2},{2,2,2,2,2,2},{2,2,2,2,2,2}};
  bool encontrar(1);
  int* ptr=*matriz+2;
  imprimir(*matriz,6);
  Jugar(*matriz, 6,5);





  return 0;
}