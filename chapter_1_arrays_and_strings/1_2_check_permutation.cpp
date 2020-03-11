#include <iostream>
#include <map>

/*
Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

My first thought in this one is about the best O of the algorithm, which is O(2n) minimum, since both strings have to at least 
be read once. So, thinking about it, it's clear to see if strings have different sizes, then they are not permutations, so that must
be treated first. After that I try to use map, since I think is normally a great way to deal with counting stuff. So, If I count the 
times a letter appears in the first word I analyze (simply adding 1 in the map, which starts at 0) and then in the other word I 
remove 1 in the map for each use of the letter, if in any moment the map value is lower than 0, then there is no permutation. Once again, 
after that, I have to verify if any of the values in the map is greater than 0, which means there is no permutation neither. Only if all
the values are equal to 0 at the end the word is a permutation.

After all the code complexity is O(n) which is the best possible, so I'm satisfied.
*/

using namespace std;

int main(){
  map<char, int> count;
  string word1, word2;
  cin >> word1;
  cin >> word2;
  if(word1.size() != word2.size()){
    cout << "Nao e permutacao\n";
    return 0;
  }
  for(auto l: word1){
    count[l] += 1;
  }
  for(auto l: word2){
    count[l] -= 1;
    if(count[l] < 0){
      cout << "Nao e permutacao.\n";
      return 0;
    }
  }
  for(auto c: count){
    if(get<1>(c) > 0){
      cout << "Nao e permutacao.\n";
      return 0;
    }
  }
  cout << "E permutacao";
}
