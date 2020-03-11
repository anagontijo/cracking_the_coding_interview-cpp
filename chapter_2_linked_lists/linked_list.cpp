#include <iostream>

using namespace std;

class node{
  public:
    int value;
    node* next;
    node* prev;
    node();
    node(int v);
    node(int v, node* p, node* n);
};

node::node(){
  value = 0;
  next = nullptr;
  prev = nullptr;
}

node::node(int v){
  value = v;
  next = nullptr;
  prev = nullptr;
}

node::node(int v, node* p, node* n){
  value = v;
  next = n;
  prev = p;
}

class linked_list{
  public:
    node* base;
    int size;
    linked_list();
    void add_node(node* n);
    void remove_node(int val);
    void remove_node(node* rem);
    node* search_node(int val);
    void print_list();
};

linked_list::linked_list(){
  base = new(node);
  base->next = base;
  base->prev = base;
  size = 0;
}

void linked_list::add_node(node* n){
  node* aux = base->prev;
  aux->next = n;
  n->prev = aux;
  base->prev = n;
  n->next = base;
}

node* linked_list::search_node(int val){
  node* now = base->next;
  while(now != base){
    if(now->value == val){
      return now;
    }
    now = now->next;
  }
  return nullptr;
}

void linked_list::remove_node(node* rem){
  node* aux = rem->next;
  rem->prev->next = aux;
  aux->prev = rem->prev;
}

void linked_list::remove_node(int val){
  node* rem = search_node(val);
  if(rem != nullptr){
    remove_node(rem);
  }
}

void linked_list::print_list(){
  node* now = base->next;
  while(now != base){
    cout << now->value << ", ";
    now = now->next;
  }
  cout << endl;
}
