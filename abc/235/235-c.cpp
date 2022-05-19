#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main() {
  int n,q;
  int ai,xi,ki,ans;
  cin >> n >> q;
  map<int,int> a;
  map<int,vector<int>> ac;

  rep(i,n){
    cin >> ai;
    
    if(a.count(ai)){
      ++a[ai];
    }else{
      a[ai] = 1;
    }
    ac[ai].push_back(i+1);
  }

  rep(i,q){
    cin >> xi >> ki;
    --ki;
    ans = -1;
    if(a.count(xi)){
      if(ki < ac[xi].size()){
        ans = ac[xi][ki];
      }
    }
    cout << ans << endl;
  }

}
