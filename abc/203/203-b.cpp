#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,k,ans=0;
  cin >> n >> k;

  for(int i=1; i<=n; ++i){
    for(int j=1; j<=k; ++j){
      ans += i*100+j;
    }
  }

  cout << ans;
}
