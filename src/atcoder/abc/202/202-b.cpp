#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  int len = s.length();
  reverse(s.begin(), s.end());
  
  for(int i=0; i<len; ++i){
    if(s.at(i)=='6'){ s.at(i)='9'; continue; }
    if(s.at(i)=='9'){ s.at(i)='6'; continue; }
  }
  
  cout << s;
}
