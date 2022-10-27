#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,ans;
  cin >> a >> b;
  
  if(a+b>=15 && b>=8) ans=1;
  else{
    if(a+b>=10 && b>=3) ans=2;
    else{
      if(a+b>=3) ans=3;
      else ans=4;
    }
  }
  
  cout << ans;
}
