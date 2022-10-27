#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int s,t,x;
  cin >> s >> t >> x;

  if(s<t) puts(s<=x && x<t ? "Yes" : "No");
  else puts(x<t || s<=x ? "Yes" : "No");
}
