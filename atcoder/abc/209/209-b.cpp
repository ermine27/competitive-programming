#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,x,ai,total=0;
  cin >> n >> x;
  for(int i=0; i<n; ++i){
    cin >> ai;
    if(i%2==1) --ai;
    total += ai;
  }
  if(total <= x) cout << "Yes";
  else cout << "No";
}
