#include <bits/stdc++.h>
using namespace std;


#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define repf(i,n,s) for(int i = (int)(s); i < (int)(n); ++i)
using ll = long long;
using vl = vector<ll>;

 ll solve(vl s){
  ll ans = 0;
  
  rep(i,3)
    repf(j,4,i+1)
      repf(k,5,j+1) ans += s[i]*s[j]*s[k];

  return ans;
}

int main() {
  int n;
  cin >> n;
  string si;
  vl s(5,0);

  rep(i,n) {
    cin >> si;
    switch(si[0]){
      case 'M':  ++s[0]; break;
      case 'A':  ++s[1]; break;
      case 'R':  ++s[2]; break;
      case 'C':  ++s[3]; break;
      case 'H':  ++s[4]; break;
    }
  }
  
  cout << solve(s);
}
