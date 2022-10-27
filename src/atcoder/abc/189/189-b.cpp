#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x,i,vi,pi,sum = 0;
  cin >> n >> x;
  
  x *= 100;
  i = 0;
  while(i < n && sum <= x){
    cin >> vi >> pi;
    sum += vi * pi;
    ++i;
  }
  if(sum > x) cout << i;
  else cout << -1;
  
}
