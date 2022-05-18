#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,ans;
  cin >> a >> b;
  if(a>b) ans=0;
  else ans=b-a+1;
  cout << ans;
}
