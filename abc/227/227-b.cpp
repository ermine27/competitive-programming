#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> AB;

  int xy;
  for(int i=1; i<=250; ++i){
    for(int j=1; j<=250/i; ++j){
      xy = 3 * (i + j) + 4 * i * j;
      if(xy > 1000) break;
      AB.push_back(xy);
    }
  }

  int ans = 0;
  int si;
  for(int i=0; i<N; ++i){
    cin >> si;
    if(count(AB.begin(), AB.end(), si) == 0) ++ans;
  }
  cout << ans;
}
