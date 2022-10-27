#include <bits/stdc++.h>
using namespace std;

int main() {  
  string s,t;
  cin >> s >> t;
  int len = s.size();

  for(int i=0; i<26; ++i){
    if(s == t){
      cout << "Yes";
      return 0;
    }
    
    for(int j=0; j<len; ++j){
      if(s.at(j) == 'z'){
        s.at(j) = 'a';
      } else {
        s.at(j) = s.at(j)+ 1;
      }
    }
    
  }

  cout << "No";
}
