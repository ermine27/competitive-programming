#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));

  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      cin >> a.at(i).at(j);
    }
  }

  for(int i1=0; i1<h-1; ++i1){
    for(int j1=0; j1<w-1; ++j1){
      for(int i2=i1+1; i2<h; ++i2){
        for(int j2=j1+1; j2<w; ++j2){
          if( a.at(i1).at(j1) + a.at(i2).at(j2) > a.at(i2).at(j1) + a.at(i1).at(j2) ){
            cout << "No";
            return 0;
          }
        }
      }
    }
  }
  cout << "Yes";
  return 0;
}
