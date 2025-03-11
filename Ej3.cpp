#include "Ej3.h"



int main(){ 
    return 0; 
}

shared_ptr<Node> creat_node(u_int8_t value){ 
    shared_ptr<Node> newNode = make_shared<Node>();
    newNode->value = value; 
    newNode->next = nullptr; 
    return newNode; 
}


void push_front(shared_ptr<Node> newNode, List list){ 
    newNode->next =move(list.head); 
    list.head = move(newNode); 
}

void push_back(shared_ptr<Node> newNode, List list){    
    list.tail->next = move(newNode); 
    list.tail = move(newNode); 
}

void instert(shared_ptr<Node> newNode,int index, List list){
    shared_ptr<Node> currentNode = list.head; 
    for(int i; i< index; i++){ 
        if (currentNode == nullptr || currentNode->next == nullptr) {
            cerr << "Index out of range";
            return;
        }
        currentNode=move(currentNode->next); 
    }
    newNode->next = move(currentNode->next); 
    currentNode->next = move(newNode);  
}

void erase(List list,int index){ 
if (index == 0) {
    list.head = move(list.head->next);
    if (list.head == nullptr) {
        list.tail = nullptr;
    }
    return;
}

shared_ptr<Node> currentNode = list.head;
for (int i = 0; i < index - 1; i++) {
    if (currentNode == nullptr || currentNode->next == nullptr) {
        cerr << "Index out of range";
        return;
    }
    currentNode = move(currentNode->next);
}

// chequear
currentNode->next = move(currentNode->next->next);
if (currentNode->next == nullptr) {
    list.tail = currentNode;
}
}

void print_list(List list) {
    shared_ptr<Node> currentNode = list.head;
    while (currentNode != nullptr) {
        cout << static_cast<int>(currentNode->value) << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}



