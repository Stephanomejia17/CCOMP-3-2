 // Trabajo de:      Justo Alfredo Perez Choque


#include<iostream>
#include<fstream> //leer el txt
#include<string.h>//Para copiar cada linea del txt al array


using namespace std;

void leer_archivo(char *p,char (*q)[13])
{    
    ifstream archivo;
    string texto;
    archivo.open("sopa.txt",ios::in);
    if (archivo.fail()) {cout<<"No se pudo abrir el archivo, tal vez la direccion del txt es incorrecta";exit(1);}
    for (int i = 0 ;i < 13 ; i++)
    {
        getline(archivo,texto);//Esta funcion a veces no la reconoce visual studio code, pero no da error
        if ( i == 0)strcpy(p, texto.c_str());     
        else strcpy(*(q+(i-1)), texto.c_str());
    }
    
    
}
void imprimir(char *m, int dim1, int dim2)
{    
    char *p= m;
    char *q= m;
    while (p< (m)+(dim1*dim2))
    {
        while (p< q+(dim2))
        {   
            cout<<*p<<" ";
            p++;
        }
        cout<<endl;
        q = q+dim2;
    }
}
void imprimir_respuesta(char *m, int dim1, int dim2 , char *palabra, int tamanho_real_palabra,char *rpta,int operacion)
{
    //Este imprimir respuesta solo vuelve todo en guiones, y los elementos encontrados los vuelve a escribir para viusualizarlos
    char *p= m;
    char *q= m;
    while (p< (m)+(dim1*dim2))
    {
        while (p< q+(dim2))
        {   
            if (*p) *p = '-';
            p++;
        }
        q = q+dim2;
    }
    for (char *u = palabra ; u< palabra + tamanho_real_palabra;u++)
    {
        *rpta = *u;
        rpta= rpta  +(operacion);
    }
    imprimir(m,12,13);
    
    
}
void direccion(int operacion)
{
    switch (operacion)
    {
    case -13:
        cout<<"Encontrado (Hacia Arriba)"<<endl;break;
    case 13:
        cout<<"Encontrado (Hacia Abajo)"<<endl;break;
    case -12:
        cout<<"Encontrado (Diagonal superior derecha)"<<endl;break;
    case -14:
        cout<<"Encontrado (Diagonal superior izquierda)"<<endl;break;
    case 14:
        cout<<"Encontrado (Diagonal inferior derecha)"<<endl;break;
    case 12:
        cout<<"Encontrado (Diagonal inferior izquierda)"<<endl;break;
    case 1:
        cout<<"Encontrado (Hacia la derecha)"<<endl;break;
    case -1:
        cout<<"Encontrado (Hacia la izquierda)"<<endl;break;
    default:
        break;
    }
}
void recorrer(char *p,char *r,char **q, char *palabra,int tamanho_real_palabra,char **rpta, bool &encontrado,int operación, int &sentido)
{
    //Esta funcion hace todo el trabajo, va recorriendo y comparando, es mas simple de lo que parece.
    if (encontrado == false) //if para no hacer iteracion innecesarias 
    {
        char *temp = *q;//Este temp es el puntero que se ira moviendo y comprobando
        int contador =0;//El contador almacena cuantas coincidencias de letras hay, si las coincidencias son iguales linea 100, se encontro la respuesta.
    
        for(char *s= palabra; s<palabra+tamanho_real_palabra;s++)   //for que recorre la palabra a buscar.
        {
            if(encontrado == true) break;   //EL mismo if para no hacer iteracion innecesaria
            if(*temp != *s)break;           //Si hay una discrepancia se sale y continua con el siguiente q.
            if (*temp == *s)contador++;     //Si hay una coincidencia aumenta en 1 el contador.
            if (contador == tamanho_real_palabra )// Si hay coincidencia total la respuesta se encontro.
            {
                encontrado = true;  //se encontro
                direccion(operación);//Esta funcion innecesaria xd, solo dice la direccion es un switch, me sirvio para comprobar las direcciones
                cout<<'"'<< palabra<<'"'<<" -> ";
                cout<< " ("<< (( *q-r)/13)+1<<", "<<( *q-(p))+1<<")"<<endl<<endl;//una arimetica de punteros que nos arrojas las filas y columnas
                
                
                (*rpta) = (*q);//respuesta apuntara a q, osea la primera letra que apunta
                
                sentido= operación;//sentido almacenara el sentio (-13,13,-1,1,-12,-14,12,14).
                break;
            }
          
            temp = temp+operación;    
            
        }
        
    }
    
}




int main()
{
    /*
    Buenaaaaaas profe, como ya pudo ver lo horrible esta en las funciones, trate de dejar el main impecable.
        Nota: La forma en que busca es ir hacia cada direccion donde puede estar la palabra, sino se cumple con la primera letra
              deja de buscar y pasa con la siguiente y asi con cada letra, si encuentra la palabra se detiene para ya no hacer calculos innecesarios
              Las direccion se calculan con una suma de posiciones que son las siguientes(-13,13,-1,1,-12,-14,12,14) las puede ver en linea 159-166
    */
    char palabra[13];       //La palabra que se buscara
    char sopa[12][13];      //La matriz 2D, sobre las dimensiones, le mandé un correo pero al final lo deje en 13 porque me daba errores con 12 
    
    char *q = sopa[0];      //puntero a la primera posicion del array, es tipo char y avanzara un char.
    char *r = sopa[0];      //puntero a la primera posicion del array, es tipo char y avanzara un char.
    char *respuesta ;       //Este puntero guardara la direccion de memoria de la respuesta.

    leer_archivo(palabra,sopa);//funcion que lle el txt, basicamente este inicia la matriz y el array
    
    bool encontrado = false;              //un bool para que ya no siga buscando, si lo encuentra se vuelve true y para la busqueda
    int sentido;                          //Un entero que guardará la direccion en la que está la palabra. la guarda como un número(-13,13,-1,1,-12,-14,12,14)
    int tamanho_real_palabra = strlen(palabra);     //Tamaño de la palabra que busca

    imprimir(sopa[0],12,13);cout<<endl<<endl;       //Una impresion de la sopa de letras.
//#######################################################################################################
//                          Inicio de algoritmo
//#######################################################################################################

    for (char (*p)[13] = sopa; p< sopa +12 ; p++)       //un for con un puntero p que avanza, son las filas, es de tipo array, asi que avanza un array por iteracion
    {
        while((q < (*p)+13) && encontrado == false)     //Este while, hace que q recorra toda la fila uno por uno
        {
            
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,-13,sentido);//(Hacia Arriba)
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,+13,sentido);//(Hacia Abajo)
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,-1,sentido);//(Hacia la izquierda)
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,+1,sentido);//(Hacia la derecha)
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,-12,sentido);//(Diagonal superior derecha)
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,-14,sentido);//(Diagonal superior izquierda)
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,+12,sentido);//(Diagonal inferior izquierda)
            recorrer(*p,r,&q,palabra,tamanho_real_palabra,&respuesta,encontrado,+14,sentido);//(Diagonal inferior derecha)
            q++;    
            
        }
        
        if(encontrado == true ) //En el algoritmo hay varios if de este tipo, es para que no se hagan iteraciones innecesarias, a veces hasta daban error, asi que quedan de lujo
        {
            break;
        }
        
        q = *(p);     //El puntero q, apuntara a la siguiente fila y recorrera cada char que haya adentro
        
    }
//#######################################################################################################
//                          Fin de algoritmo
//#######################################################################################################

    if(encontrado == true ) 
        {
           //Si se encontro, imprime la respuesta, el puntero respuesta almacena la dirección
           //La variable sentido el sentido en el que esta (-13,13,-1,1,-12,-14,12,14).
           
            imprimir_respuesta(sopa[0],12,13,palabra,tamanho_real_palabra,respuesta,sentido);
            
        }

    else cout<<"No se encontro la palabra -> "<<palabra<<endl<<"-1"<<" -1"<<endl;
    

}