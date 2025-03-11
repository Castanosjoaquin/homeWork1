#include <iostream>
#include <memory>

using namespace std;  

struct Node{ 
    shared_ptr<Node> next; 
    int value;
}; 

struct List{
    shared_ptr<Node> head; 
    shared_ptr<Node> tail; 
    u_int8_t size;

    List(nullptr_t h ,u_int8_t s ) : head(h), size(s){}
};

shared_ptr<Node> creat_node(u_int8_t value); 
void push_front(shared_ptr<Node> newNode, List list); 
void push_back(shared_ptr<Node> newNode, List list); 
void instert(shared_ptr<Node> newNode,int index, List list);
void erase(List list,int index); 
void print_list(List list); 
