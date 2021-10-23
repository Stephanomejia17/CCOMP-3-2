#include <iostream>
#include <fstream>
using namespace std;

char* puntero_final(char* a){
  char* p;
  while(*a){
    p=a;
    a++;
  }
  return p;
}

void leer(char* sopa[6][6],char* word){
  ifstream fin("sopa.txt"); // añadimos el archivo
  
  fin>>*word; //subimos la primera fila

  //subimos la sopa
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      fin>>sopa[i][j];
    }
  }
}
//void print(){}

void recorrer(char* m,int dim1, int dim2,int dim3,bool& encontrardo,char* word,int orientacion){
  char* p = m;
  char* q = m;
  char* s = m;
  bool opuesto=false;
  int cont;
  while(p<m+(dim1*dim2*dim3))
  {
  p=s;
  while(p<s+(dim1*dim2)&&encontrardo==false){
    p=q;
    char* aux_word=word;
    char* aux_inver=puntero_final(word);
    while(p<q+(dim2)){
      if(*p!=*aux_word&&opuesto==false){
        break;
      }
      if(*p!=*aux_inver){
        opuesto=true;
        break;
      }
      p+=orientacion+(dim1*dim2);
      cont++;
      if(opuesto){
        aux_inver--;
        continue;
      } 
      aux_word++;
    }
    if(cont>=(puntero_final(word)-word)+1){
      encontrardo=true;
      break;
    }
    cout<<endl;
    q+=dim2;
  }
  s+=dim3*dim2;
  cout<<endl<<endl;
  }
}

int main(){
/*
  ifstream fin("sopa.txt"); // añadimos el archivo
  char word [13];
  char  sopa[7][7][7];
  bool encontrado=false;
  
    
  fin>>word; //subimos la primera fila

  //subimos la sopa
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      fin>>sopa[i][j];
    }
  }
  cout<<((*sopa)+2);

  int prueba[6][6][6];
  int something=0;
  for(int k=0;k<6;k++){
    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++){
        prueba[k][i][j]=something;
        something++;
      }
    }
  }
  int ptr_prueba=*prueba;

  //recorrer(**prueba,6,6,6);
  
  
  for(int k=0;k<6;k++){
    cout<<endl<<"PLANO "<<k+1<<endl;
    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++){
        cout<<prueba[k][i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl<<endl;
  }*/
  //ptr_prueba+=47;
  //cout<<*ptr_prueba;

  char a[12]{"GATO"};
  cout<<((a+3)-(a));

  return 0;
}