#include <iostream>
using namespace std;

int main(){
    int cont(0);
    int num = 1;
  for(int x1=0;x1<6;x1++){
    for(int x2=1;x2<9;x2++){
      for(int x3=0;x3<15;x3++){
        int suma=x1+x2+x3;
        
        if(suma==15){
            cout << num <<". "<< suma << endl;
          cont++;
          num++;
        }
      }
    }
  }
  cout<<cont;
    

}

    