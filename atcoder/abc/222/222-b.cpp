#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,p,ai,ans=0;
  cin >> n >> p;
  for(int i=0; i<n; ++i){
    cin >> ai;
    if(ai<p) ++ans;
  }
  cout << ans;
}
