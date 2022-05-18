#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int64_t n,mm;
  cin >> n;

  int k=0;
  while(k<1000000000){
    mm=(int64_t)pow(2,k+1);
    if(n<mm) break;
    ++k;
  }
  cout << k;
  
}
