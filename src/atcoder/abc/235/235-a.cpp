#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main() {
  int ans=0;
  char c;

  rep(i,3){
    cin >> c;
    ans += c - '0';
  }

  cout << ans * 111;
}
