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
};

shared_ptr<Node> creat_node(int value); 
void push_front(int value, List &list); 
void push_back(int value, List &list); 
void insert(int value,int index, List &list);
void erase(List &list,int index); 
void print_list(List &list); 
