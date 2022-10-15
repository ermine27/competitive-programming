#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,ans=6;
  cin >> n;

  if(n<=125) ans=4;
  if(n>=212) ans=8;
  cout << ans;
  
}
