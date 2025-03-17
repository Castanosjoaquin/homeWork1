#include "Ej3.h"



int main(){ 


    List list; 
    list.head = nullptr; 
    list.size = 0 ;


    push_front(1, list);
    push_front(2, list);
    push_front(3, list);

    push_back(4,list); 
    push_back(5,list); 
    print_list(list); 

    insert(5,1,list);    
    print_list(list); 
    insert(6, 2, list);
    print_list(list);
    erase(list, 0 ); 
    print_list(list); 

    erase(list,3);
    print_list(list); 



    return 0; 
}

shared_ptr<Node> creat_node(int value){ 
    shared_ptr<Node> newNode = make_shared<Node>();
    newNode->value = value; 
    newNode->next = nullptr; 
    return newNode; 
}


void push_front(int value, List &list){ 
    shared_ptr<Node> newNode = creat_node( value); 
    newNode->next = list.head; 
    list.head = newNode; 
    list.size ++; 
}

void push_back(int value, List &list){    
    shared_ptr<Node> newNode = creat_node( value); 
    if(list.head ==  nullptr){ 
        list.head=  newNode;
    }
    else{ 
        shared_ptr<Node> curr = list.head; 
        while (curr->next != nullptr){
            curr = curr->next;  
        }
        curr->next = newNode; 
    }
    list.size ++ ;
}

void insert(int value ,int index, List &list){
    if(index > list.size) {
        cout<<"index out range, so the element has been insert at the end of the list"<< endl; 
        push_back(value, list);
        return; }
    if(index ==0 ){  push_front(value, list); return; }

    shared_ptr<Node> newNode = creat_node( value); 
    shared_ptr<Node> currentNode = list.head; 
    for(int i =0 ; i< index-1; i++){ 
        currentNode=currentNode->next; 
    }
    newNode->next = currentNode->next; 
    currentNode->next = newNode;  
    list.size ++; 
}

void erase(List &list,int index){ 
    if(index > list.size) {cout<<"Out of index"; return; }

    if(index == 0){ 
        list.head= list.head->next; 
        list.size--; 
        return; 
    }
    shared_ptr<Node> currentNode = list.head; 
    for (int i = 0; i < index - 1; i++) {
        currentNode =currentNode->next;
    }
    currentNode->next = currentNode->next->next;
    list.size --; 
    }

void print_list(List &list) {
    shared_ptr<Node> currentNode = list.head;

    while (currentNode != nullptr) {
        cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}



