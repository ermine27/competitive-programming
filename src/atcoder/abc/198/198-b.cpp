#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string n,r;
  cin >> n;
  int l=n.length();
  
  for(int i=0; i<l; ++i){
    r=n;
    reverse(r.begin(), r.end());
    if(n==r){
      cout << "Yes";
      return 0;
    }
    n = '0' + n;
  }
  
  cout << "No";
}
