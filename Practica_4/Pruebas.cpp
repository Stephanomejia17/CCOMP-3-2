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
  char* text[12];
  char** ptr=text;



  for(int i=0;i<12;i++){
    *(text+i)= *(sopa+i);
  }
  char* move(*ptr);




  for(int h=0;h<12;h++){
    for(int j=0;j<12;j++){
      int i=0;
      //oeste
      if(j-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move--;
          ptr_w++;
        }
        move+=i;
        ptr_w-=i;
      }
      //noroeste
      if(j-len(word)>=-1 && h-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move-=14;
          ptr_w++;
        }
        move+=i*14;
        ptr_w-=i;
      }
      //norte
      if(h-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move-=13;
          ptr_w++;
        }
        move+=i*13;
        ptr_w-=i;
      }
      //noreste
      if(h-len(word)>=-1 && j+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move-=12;
          ptr_w++;
        }
        move-=i*12;
        ptr_w-=i;
      }
      //este
      if(j+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move++;
          ptr_w++;
        }
        move-=i;;
        ptr_w-=i;
      }
      //sureste
      if(h+len(word)<=12 && j+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move+=14;
          ptr_w++;
        }
        move-=i*14;
        ptr_w-=i;
      }
      //sur
      if(h+len(word)<=12){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move+=13;
          ptr_w++;
        }
        move-=i*13;
        ptr_w-=i;
      }
      //suroeste
      if(h+len(word)<=12 && j-len(word)>=-1){
        for(i=0;i<len(word);i++){
          if(*move!=*ptr_w){
            break;   
          }
          move+=12;
          ptr_w++;
        }
        move-=i*12;
        ptr_w-=i;
      }
      
      if (i==len(word)-1){
        encontrado=true;
        cout<<"x = "<<h;
        cout<<endl<<"y = "<<j<<endl;
      }
      move += 1;
    }
    move += 1;

  }


  if(encontrado==false){
    cout<<"x=  -1 ,y= -1";
  }



  return 0;
}
/*#include <iostream>
using namespace std; 

int main(){
    int cont = 0;
    char Sopa[5][5]=
    {
    {'a' , 'b' , 'c' , 'd' , 'e'} ,
    {'f' , 'g' , 'h' , 'i' , 'j'} ,
    {'1' , '2' , '3' , '4' , '5'} ,
    {'6' , '7' , '8' , '9' , '0'} ,
    {'1' , '2' , '3' , '4' , '5'}
    };

    char (*ptrSopa)[5] = Sopa;

    while(*(*ptrSopa+cont) != '\0'){
        cout << *(*ptrSopa+cont) << " ";


        cont++;
    }

}*/