#include "linked_list.cpp"
#include <vector>
#include <map>

/*
Remove Dups: Write code to remove duplicates from an unsorted linked list.
(How would you solve this problem if a temporary buffer is not allowed)

So, in this example as most of the times I use a map to count frequency. Count begins at 0, everytime a value is visited it adds up 1
in the counter. If the counter is greater than 1 for said value, the node is removed.
*/

using namespace std;

void remove_dups(linked_list ll){
  node* now = ll.base->next;
  while(now != ll.base){
    count[now->value] += 1;
    now = now->next;
    if(count[now->prev->value] > 1){
      ll.remove_node(now->prev);
    }
  }
}
