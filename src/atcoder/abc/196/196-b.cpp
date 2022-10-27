#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string x;
  cin >> x;
  char c;
  int l=x.length();

  for(int i=0; i<l; ++i){
    c = x.at(i);
    if(c == '.') return 0;
    cout << c;
  }
}
