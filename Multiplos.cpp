#include <iostream>
using namespace std;
int len(char* a){
  int cont=0;
  while(*a){
    cont++;
  }
  return cont;
}

char sopa[13][13]={"AGMUSSOPAASO","GPPMRWARTVOG","OTTEEGIEURER","HIPPOROTAMUS","EAEIAGGGIITZ","GPPTPANIAGTE","PANTERAITIEB","EELPKEEAMRRR","TDODRAPOELFA","ALTAKREEMFLT","CJAREPEGHTWU","YUKEETHCXSDJ"};
char word[10]{"Tigre"};

bool encontrado=false;


int main(){
  char* ptr_w=word;
  char** ptr= new char*[13];

  for(int i=0;i<12;i++){
    *(ptr+i)= new char[13];
  }
  for(int i=0;i<13;i++){
    for(int j=0;j<13;j++){
      *(*(ptr+i)+j)= *(*(sopa+i)+j);
    }
  }
  for(int h=0;h<13;h++){
    for(int j=0;j<13;j++){
      int cont(0);
      int i=0;
      //oeste
      if(j-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)--;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      //noroeste
      if(j-len(word)>=-1 && h-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)++;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      //norte
      if(h-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)++;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      //noreste
      if(h-len(word)>=-1 && j+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)++;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      //este
      if(j+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)++;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      //sureste
      if(h+len(word)<=12 && j+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)++;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      //sur
      if(h+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)++;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      //suroeste
      if(h+len(word)<=12 && j-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(**ptr!=*ptr_w){
            break;   
          }
          cont++;
          (*ptr)++;
          ptr_w++;
        }
        *ptr-=i;
        ptr_w-=i;
      }
      (*ptr)++;
      if (cont==len(word)){
        encontrado=true;
        cout<<"x = "<<h;
        cout<<endl<<"y = "<<j<<endl;
      }
    }
    ptr+=1;

  }


  if(encontrado==false){
    cout<<"x=  -1 ,y= -1";
  }

for(int i=0;i<13;i++){
    delete ptr[i];
  }
  delete[] ptr;


  return 0;
}