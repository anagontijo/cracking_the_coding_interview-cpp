#include <iostream>
#include <map>

using namespace std;

int main(){
  string word;
  map<char, int> count;
  cin >> word;
  for(int i = 0; i < (int)word.size(); i++){
      count[word[i]] += 1;
      if(count[word[i]] > 1){
        cout << "It's not unique.\n";
        return 0;
      }
  }
  cout << "It's unique.\n";
}
