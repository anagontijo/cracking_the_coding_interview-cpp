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
  node* now = ll.base->next;
  ll.print_list();
  while(now != ll.base){
    count[now->value] += 1;
    now = now->next;
    if(count[now->prev->value] > 1){
      ll.remove_node(now->prev);
    }
  }
  ll.print_list();
}
