#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int s,t,ans=0;
  cin >> s >> t;

  for(int i=0; i<=100; ++i){
    for(int j=0; j<=100-i; ++j){
      for(int k=0; k<=100-i-j; ++k){
        if(i+j+k <= s && i*j*k <= t) ++ans;
      }
    }
  }
  cout << ans;
  
}
