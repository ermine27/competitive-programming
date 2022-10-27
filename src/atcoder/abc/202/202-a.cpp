#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,ans=0;

  for(int i=0; i<3; ++i){
    cin >> a;
    ans += 7-a;
  }

  cout << ans;
}
