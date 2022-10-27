#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b;
  cin >> a >> b;
  string ans = "Alloy";
  
  if(b==0) ans="Gold";
  if(a==0) ans="Silver";
  
  cout << ans;
}
