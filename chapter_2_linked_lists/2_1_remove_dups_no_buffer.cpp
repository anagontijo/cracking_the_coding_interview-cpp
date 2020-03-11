#include "linked_list.cpp"
#include <vector>

/*

Remove Dups: Write code to remove duplicates from an unsorted linked list.
(How would you solve this problem if a temporary buffer is not allowed) <<<

So, for solving this problem without using a buffer every node must be compared to all of it's next nodes in the linked list.
This solution takes O(N^{2}) time, which is a lot worse then the O(N) when using buffer but takes O(1) space whereas a buffer takes up
O(N) space.

So, basically we must iterate over each node, and for each of them iterate over all the nodes that are after them.
But not the ones before them. Why?
Because If the current node had the same value as any before of it, than it would have been deleted before.

*/


using namespace std;

int main(){
  linked_list ll;
  vector<node> n(7);
  for(int i = 0; i < 7; i++){
    n[i] = i%4;
    ll.add_node(&n[i]);
  }
  
  // General part of the code
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
}
