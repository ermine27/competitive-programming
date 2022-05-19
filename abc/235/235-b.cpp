#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int n,hi,ans=0;
  cin >> n;
  rep(i,n){
    cin >> hi;
    if(chmax(ans,hi) == false) break;;
  }

  cout << ans;
}
