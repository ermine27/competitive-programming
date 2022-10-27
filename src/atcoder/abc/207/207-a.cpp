#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,c;
  cin >> a >> b >> c;

  cout << a+b+c-min(a,min(b,c));
}
