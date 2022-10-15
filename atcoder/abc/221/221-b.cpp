#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t,s2;
  cin >> s >> t;
  
  if(s==t){
    cout << "Yes";
    return 0;
  }
  for(int i=0; i<s.length()-1; ++i){
    s2=s;
    swap(s2.at(i), s2.at(i+1));
    if(s2==t){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
