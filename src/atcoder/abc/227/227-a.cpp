#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,A,ans;
  cin >> N >> K >> A;

  ans=(A+K-1)%N;
  if(ans==0) ans=N;
  
  cout << ans;
}
