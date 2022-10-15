#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, d, aMax=0, bMin=1000;
  cin >> n;
  
  for(int i=0; i<n; ++i){
    cin >> d;
    aMax = max(aMax, d);
  }
  for(int i=0; i<n; ++i){
    cin >> d;
    bMin = min(bMin, d);
  }

  cout << max(0, bMin - aMax + 1);
}
