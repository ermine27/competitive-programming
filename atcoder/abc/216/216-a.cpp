#include <bits/stdc++.h>
using namespace std;

int main(void) {
  float input;
  int xy,x,y;
  cin >> input;
  xy=input*10;
  x=xy/10;
  y=xy%10;
  cout << x;
  if(y<=2) cout << '-';
  if(y>=7) cout << '+';
}
