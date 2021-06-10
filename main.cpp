#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){

    LinkedList pila;
    int dato,size;
    cout<<"Ingrese cantidad de datos: "<<endl;
    cin>>size;
    for(size_t i=0;i<size;i++){
        cout<<"ingrese un numero"<<endl;
        cin>>dato;
        pila.insert(dato);
    }
    
    cout<<"\nMostrando los elementos de la lista."<<endl;
    pila.print();

    cout<<"\nBuscando elemento en la lista."<<endl;
    pila.search(4);

    cout<<"\nEliminando el 3 de la lista."<<endl;
    pila.remove(3);

    cout<<"\nMostrando los elementos de la lista."<<endl;
    cout<<pila<<endl;

    return 0;
}
