#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define repf(i,n) for(int i = 1; i <= (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  rep(i,26){
    rep(j,15){
      if(i*4+j*7 == n){
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
