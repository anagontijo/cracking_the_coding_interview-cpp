#include <iostream>
#include "linked_list.cpp"


/*
Return Kth to Last: Implement an algorithm to find the kth to last element of a
singly linked list.

Ok, the problem with this one is it is poorly written, but what it means is:
I want the Kth element of the inversed linked list. If it was a double linked
list it would be easy, just go backwards k times. With a singly linked list it
gets complicated, but my solution would be to start from the begining and "walk"
for k nodes (if there aren't k nodes, there is no solution). Then, I start to
"walk" with both the node I started walking and the begin node again. Once the
first node hits the end, the second node will be the answear.
*/

node* kth_to_last(linked_list ll, int k){
  node* first_node = ll.base->next;
  for(int i = 0; i < k; i++){
    // This will be the kth + 1 element by the end of this
    first_node = first_node->next;
  }
  node* second_node = ll.base->next;
  while(first_node != ll.base){
    first_node = first_node->next;
    second_node = second_node->next;
  }
  return second_node;
}

int main(){
  linked_list ll;
  node nodes[3];
  nodes[0].value = 1;
  nodes[1].value = 2;
  nodes[2].value = 3;
  ll.add_node(&nodes[0]);
  ll.add_node(&nodes[1]);
  ll.add_node(&nodes[2]);
  ll.print_list();

  node* result = kth_to_last(ll, 2);
  cout << result->value << endl;
}
