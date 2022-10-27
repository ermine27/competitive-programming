#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main() {
  int c=0,cmax=0;
  string s;
  cin >> s;

  rep(i, s.size()){
    if(s.at(i) == 'A' || s.at(i) == 'C' || s.at(i) == 'G' || s.at(i) == 'T'){
      ++c;
      cmax = max(cmax,c);
    }
    else c=0;
  }
  cout << cmax;
}
