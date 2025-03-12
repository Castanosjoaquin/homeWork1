#include <iostream>
#include <memory>

using namespace std;  

struct Node{ 
    shared_ptr<Node> next; 
    int value;
}; 

struct List{
    shared_ptr<Node> head; 
    u_int8_t size;

};

shared_ptr<Node> creat_node(int value); 
void push_front(shared_ptr<Node> newNode, List &list); 
void push_back(shared_ptr<Node> newNode, List &list); 
void instert(shared_ptr<Node> newNode,int index, List &list);
void erase(List list,int index); 
void print_list(List &list); 
