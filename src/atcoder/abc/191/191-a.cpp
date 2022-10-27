#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int v,t,s,d, vt, vs;
  cin >> v >> t >> s >> d;
  vt=v*t;
  vs=v*s;
  if(vt<=d && d<=vs) {
    cout << "No";
    return 0;
  }
    
  cout << "Yes";  
}
