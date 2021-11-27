#include <iostream>
using namespace std;

template <class T> //Clase Generica
class Node{
    public:
    T data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(T d){
        data = d;
        next = NULL;
    }
    void print(){
        cout << data;
    }
};

template <class T>
class List{
    public:
    Node<T>* head;
    Node<T>* end;
    List(){
        head = NULL;
        end = NULL;
    }
    ~List(){
        Node<T>* sig;
        while(head){
            sig = head->next;
            delete head;
            head = sig;

        }
    }
    void add(T d){
        Node<T>* new_node = new Node<T>(d); 
        if(!head){ //Vacia
            head = new_node;
            end = new_node;
        }
        else{
            end->next = new_node;
        }
        end = new_node;
    }
    bool find(T d, Node<T>* &ant){
        ant = NULL;
        if(head->data == d){
            ant = NULL;
            return true;
        }
        
        for(ant = head; (ant->next) && (ant->next->data != d); ant = ant->next);
        if(ant->next)
            return true;
        return false;

    }
    bool del(T e){
        Node<T>* ant;
        if(!find(e,ant)){
            cout<<"Nodo No Encontrado ";
        }
        Node<T>* tmp;
        if(!ant) // Nodo esta al inicio 
        {
            tmp = head;
            head = tmp->next;
            delete tmp;
            if(!head){
                end =NULL;
            
            }
            return true;
        }
        tmp = ant->next;
        ant->next=ant->next->next;
        delete tmp;
        
        if(ant->next==NULL){
            end=ant;
        }
        return true;
    }
    bool insert(T d, T pos){
        Node<T>* ant;
        if(find(pos,ant)){
            Node<T>* newNode = new Node<T>(d);
            if(!ant) //Esta al inicio 
            {
                newNode->next = head;
                head = newNode;
                
            } else{ //No esta al inicio
                newNode->next = ant->next;
                ant->next = newNode;
            }
            
            return true;
        }
        return false;
    }
    void print(){
        for(Node<T>* p = head;p; p = p->next){ //Hasta que p sea NULL
            p->print();
        }
        cout << "\n";
    }

};

int main(){
    List<int> l;
    l.add(5);
    l.add(7);
    l.add(2);
    Node<int>* ant;
    if(l.insert(10,2)){
        cout << "Nodo Encontrado\n";
    }
    else{cout << "Nodo No Encontrado\n";}
    l.print();
    
    return 0;
}