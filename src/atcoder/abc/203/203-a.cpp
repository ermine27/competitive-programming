#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,c,ans=0;
  cin >> a >> b >> c;

  if(a==b) ans=c;
  if(b==c) ans=a;
  if(c==a) ans=b;

  cout << ans;
}
