#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define reps(i,n) for(int i = 1; i <= (int)(n); ++i)
#define repf(i,n,s) for(int i = (int)(s); i < (int)(n); ++i)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define rreps(i,n) for(int i = (int)(n); i > 0; --i)
#define foreach(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using ll = long long;

int solve(ll n){
  int ans = 99, k = sqrt(n);
  int div, digit;
  
  reps(i,k+1){
    if(n % i == 0){
      div = n / i;
      digit = to_string(div).size();
      chmin(ans, digit);
    }
  }
  
  return ans;
}

int main() {
  ll n;
  cin >> n;
  cout << solve(n);
}
