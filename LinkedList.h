#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Node.h"
class LinkedList;

class LinkedList{
    Node* head;
    public:
        LinkedList();
        LinkedList(Node* &nodo);
        ~LinkedList();
        void insert(int elem);
        void print();
        void search(int wanted);
        void remove(int n);
        Node* getHead();
        friend std::ostream &operator << (std::ostream &out, const LinkedList &list);

};

LinkedList::LinkedList(){
    this -> head = nullptr;
}
LinkedList::LinkedList(Node* &nodo){
    this -> head = nodo;
}

void LinkedList::insert(int n){
    Node* new_node = new Node();
    new_node->elem = n;

    Node* aux1 = head;
    Node* aux2 = nullptr;
    
    while((aux1 != nullptr)&&(aux1->elem < n)){
        aux2 = aux1;
        aux1 = aux1->next;
    }
    
    if(head == aux1){
        head = new_node;
    }else{
        aux2->next = new_node;
    }

    new_node -> next = aux1;

    std::cout<<"El elemento "<<n<<" ha sido agregado correctamente."<<std::endl;
}

void LinkedList::print(){
    Node* iterator = new Node();
    iterator = head;

    while (iterator != nullptr){
        std::cout<<"|"<<iterator -> elem<<"|"<<" -> ";
        iterator = iterator -> next;
    }
}

void LinkedList::search(int wanted){ 
    bool search = false;
    Node* iterator = new Node();
    iterator = head;

    while ((iterator != nullptr) && (wanted <= iterator->elem)){
        if(iterator -> elem == wanted){
            search = true;
        }
        iterator = iterator -> next;
    }

    if(search == true){
        std::cout<<"\nEl elemento se encuentra en la lista."<<std::endl;
    }else{
        std::cout<<"\nEl elemento no se encuentra en la lista."<<std::endl;
    }
}

void LinkedList::remove(int n){
    if(head != nullptr){
        Node *aux_delete = nullptr;
        Node *before = nullptr;
        aux_delete = head;

        while((aux_delete != nullptr) && (aux_delete -> elem != n)){
            before = aux_delete;
            aux_delete = aux_delete -> next;
        }

        if(aux_delete == nullptr){
            std::cout<<"El elemento indicado no existe."<<std::endl;
        }else if(before == nullptr){
            head = head -> next;
            delete before;
        }else{
            before -> next = aux_delete -> next;
            delete aux_delete;
        }
    }
}

Node* LinkedList::getHead(){
    return head;
}
std::ostream &operator << (std::ostream &out, const LinkedList &list){
    Node* iterator = new Node();
    iterator = list.head;

    while (iterator != nullptr){
        out<<"|"<<iterator -> getElem()<<"|"<<" -> ";
        iterator = iterator->getNext();
    }

    return out;
}

LinkedList::~LinkedList(){}

#endif