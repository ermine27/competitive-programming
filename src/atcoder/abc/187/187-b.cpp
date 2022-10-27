#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, x, y, ans=0;
  cin >> n;

  vector<pair<double,double>> xy;
  for(int i=0; i<n; ++i){
    cin >> x >> y;
    xy.push_back(make_pair(x, y));
  }
  
  for(int i=0; i<n-1; ++i){
    for(int j=i+1; j<n; ++j){
      double f = (xy.at(j).second - xy.at(i).second) / (xy.at(j).first - xy.at(i).first);
      if(abs(f)<=1) ++ans;
    }
  }
  cout << ans; 
}
