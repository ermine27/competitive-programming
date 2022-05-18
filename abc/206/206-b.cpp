#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,d=0,m=0;
  cin >> n;
  
  while(m<n){
    ++d;
    m+=d;
  }
  cout << d;
}
