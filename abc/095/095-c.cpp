#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int solve(int a,int b,int c,int x,int y){
  int ans=2147483647,ta;

  for(int i=0; i<=(int)(max(x,y)); ++i){
    ta = i*c*2 + max(0,(x - i))*a + max(0,(y - i))*b;
    chmin(ans,ta);
  }
  
  return ans;
}

int main() {
  int a,b,c,x,y,ans;
  cin >> a >> b >> c >> x >> y;
  
  ans = solve(a,b,c,x,y);
  
  cout << ans;
}


