#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  int aLen = a.length();
  int bLen = b.length();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  
  int minLen = min(aLen,bLen);
  int aC, bC;
  for(int i=0; i<minLen; ++i){
    aC = a.at(i) - '0';
    bC = b.at(i) - '0';
    if(aC + bC >= 10){
      cout << "Hard";
      return 0;
    }
  }
  cout << "Easy";
}
