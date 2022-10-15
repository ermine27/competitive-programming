#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,a,p,x, pMin=1000000000;
  bool ok=false;
  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> a >> p >> x;
    if(a<x){
      pMin = min(pMin, p);
      ok=true;
    }
  }  
  
  if(ok==true)  cout << pMin;
  else cout << -1;
}
