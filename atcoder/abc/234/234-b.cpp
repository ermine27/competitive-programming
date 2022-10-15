#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define reps(i,n) for(int i = 1; i <= (int)(n); ++i)
#define repf(i,n,s) for(int i = (int)(s); i < (int)(n); ++i)
#define repfs(i,n,s) for(int i = (int)(s); i <= (int)(n); ++i)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define rreps(i,n) for(int i = (int)(n); i > 0; --i)
#define foreach(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

double solve(int n, vector<pair<int,int>> c){    
  double len, maxlen = 0.0; 
  int xlen,ylen;
  
  rep(i,n-1){
    repf(j,n,i+1){
      
      ylen = c.at(j).second - c.at(i).second;
      xlen = c.at(j).first - c.at(i).first;
      len = sqrt(pow(xlen,2) + pow(ylen, 2));

      chmax(maxlen, len);
    }
  }
  
  return maxlen;
}

int main() {
  int n;
  double ans,xi,yi;
  cin >> n;
  vector<pair<int,int>> c;
  rep(i,n){
    cin >> xi >> yi;
    c.pb(mp(xi,yi));
  }

  ans = solve(n,c);
  cout << fixed << setprecision(10);

  cout << ans;
}
