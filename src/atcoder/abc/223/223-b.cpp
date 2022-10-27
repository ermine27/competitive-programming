#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s,t,min,max;
  cin >> s;
  min = max = s;
  int len = s.length();
  for(int i=0; i<len; ++i){
    t = s.substr(i,len-i) + s.substr(0,i);
    if(t < min) min = t;
    if(t > max) max = t;
  }
  cout << min << endl;
  cout << max << endl;
}
