#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int64_t n;
  int k;
  cin >> n >> k;

  for(int i=0; i<k; ++i){
    if(n % 200 == 0) n /= 200;
    else n = n * 1000 + 200;
  }
  cout << n;
}
