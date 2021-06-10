#ifndef __NODE_H__
#define __NODE_H__
class LinkedList;

class Node{
    int elem;
    Node* next;
    public:
        Node();
        Node(int n);
        friend class LinkedList;
        void setElem(int n);
        int getElem() const;
        Node* getNext();
        friend std::ostream &operator << (std::ostream &out, const LinkedList &list);
};

Node::Node(int n){
    this -> elem = n;
    this -> next = nullptr;
}
Node::Node(){
    this -> elem = 0;
    this -> next = nullptr;
}

Node* Node::getNext(){
    return next;
}

void Node::setElem(int n){
    this -> elem = n;
}
int Node::getElem() const{
    return elem;
}

#endif