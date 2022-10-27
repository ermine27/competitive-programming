#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define repf(i,n) for(int i = 1; i <= (int)(n); ++i)
#define repfs(i,n,s) for(int i = (int)(s); i <= (int)(n); ++i)

int main() {
  int n,m,si,ci;
  cin >> n >> m;
  vector<pair<int,int>> sc(m);
    
  rep(i,m){
    cin >> si >> ci;
    sc.at(i) = make_pair(n-si,ci);
  }
  
  repfs(i, pow(10,n)-1, n==1 ? 0 : pow(10,n-1)){
    bool t = true;
    rep(j,m){
      if(sc.at(j).second != (i / (int)(pow(10,sc.at(j).first))) % 10)
        t = false;
    }

    if(t){
      cout << i;
      return 0;
    }
  }

  cout << -1;
}
