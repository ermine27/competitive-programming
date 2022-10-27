#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b,c;
  cin >> a >> b >> c;
  int ans=1, kn=1;
  if(b != a) ++kn;
  if(c != a && c != b) ++kn;

  if(kn == 3) ans = 6;
  if(kn == 2) ans = 3;
    
  cout << ans;
}
