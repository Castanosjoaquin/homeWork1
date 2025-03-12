#include "Ej3.h"



int main(){ 


    List list; 
    list.head = nullptr; 
    list.size = 0 ;
    // Create nodes
    shared_ptr<Node> node1 = creat_node(1);
    shared_ptr<Node> node2 = creat_node(2);
    shared_ptr<Node> node3 = creat_node(3);
    shared_ptr<Node> node4 = creat_node(4);
    shared_ptr<Node> node5 = creat_node(5);

    // Push nodes to the front
    push_front(node1, list);
    push_front(node2, list);
    push_front(node3, list);

    push_back(node4,list); 
    push_back(node5,list); 
    print_list(list); 

    instert(node4,1,list); 

    print_list(list); 

    



    return 0; 
}

shared_ptr<Node> creat_node(int value){ 
    shared_ptr<Node> newNode = make_shared<Node>();
    newNode->value = value; 
    newNode->next = nullptr; 
    return newNode; 
}


void push_front(shared_ptr<Node> newNode, List &list){ 
    newNode->next = list.head; 
    list.head = move(newNode); 
    list.size ++; 
}

void push_back(shared_ptr<Node> newNode, List &list){    
    if(list.head ==  nullptr){ 
        list.head=  move(newNode);
    }
    else{ 
        shared_ptr<Node> curr = list.head; 
        while (curr->next != nullptr){
            curr = curr->next;  
        }

        curr->next = newNode; // no hace falta liberar curr por q muere cuando termina la funcion
    }
    list.size ++ ;
}

void instert(shared_ptr<Node> newNode,int index, List &list){
    shared_ptr<Node> currentNode = list.head; 
    for(int i =0 ; i< index; i++){ 
        if (currentNode == nullptr || currentNode->next == nullptr) {
            cerr << "Index out of range";
            return;
        }
        currentNode=currentNode->next; 
    }
    newNode->next = currentNode->next; 
    currentNode->next = newNode;  
}

void erase(List list,int index){ 

shared_ptr<Node> currentNode = list.head; // chequear lo de sharear el pointer
for (int i = 0; i < index - 1; i++) {
    if (currentNode == nullptr || currentNode->next == nullptr) {
        cerr << "Index out of range";
        return;
    }
    currentNode = move(currentNode->next);
}

// chequear
currentNode->next = move(currentNode->next->next);

}

void print_list(List &list) {
    shared_ptr<Node> currentNode = list.head;

    while (currentNode != nullptr) {
        cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}



