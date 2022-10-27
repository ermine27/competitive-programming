#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int h,w,x,y,ans=1;
  cin >> h >> w >> x >> y;
  vector<string> s(h); 
  for(int i=0;i<h;++i) cin >> s.at(i);
  --x; --y;

  for(int i=x+1;i<h;++i){
    if(s.at(i).at(y) == '.') ++ans;
    else break;
  }
  for(int i=x-1;i>=0;--i){
    if(s.at(i).at(y) == '.') ++ans;
    else break;
  }

  for(int j=y+1;j<w;++j){
    if(s.at(x).at(j) == '.') ++ans;
    else break;
  }
  for(int j=y-1;j>=0;--j){
    if(s.at(x).at(j) == '.') ++ans;
    else break;
  }
    
  cout << ans;
}
