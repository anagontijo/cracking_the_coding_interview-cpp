#include "linked_list.cpp"
#include <vector>
#include <map>

using namespace std;

int main(){
  linked_list ll;
  vector<node> n(7);
  map<int,int> count;
  for(int i = 0; i < 7; i++){
    n[i] = i%4;
    ll.add_node(&n[i]);
  }
  ll.print_list();
  node* now = ll.base->next;
  node* aux;
  while(now != ll.base){
    aux = now->next;
    while(aux != ll.base){
      aux = aux->next;
      if(aux->prev->value == now->value){
        ll.remove_node(aux->prev);
      }
    }
    now = now->next;
  }
  ll.print_list();
}
