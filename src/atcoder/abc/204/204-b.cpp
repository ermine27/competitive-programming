#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,ai,ans=0;
  cin >> n;

  for(int i=0; i<n; ++i){
    cin >> ai;
    if(ai > 10) ans += ai-10;
  }
  
  cout << ans;
}
