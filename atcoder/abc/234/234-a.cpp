#include <bits/stdc++.h>
using namespace std;

int f(int x){
  return x*x+2*x+3;
}

int solve(int t){  
 return f(f(f(t)+t)+f(f(t)));
}

int main() {
  int t,ans;
  cin >> t;
  
  ans = solve(t);
  
  cout << ans;
}
