#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b, sa=0, sb=0;
  cin >> a >> b;

  sa = a/100 + a%100/10 + a%10;
  sb = b/100 + b%100/10 + b%10;
  cout << max(sa,sb); 
}
