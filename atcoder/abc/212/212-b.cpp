#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s, ans;
  cin >> s;

  if(s.at(0) == s.at(1) && s.at(0) == s.at(2) && s.at(0) == s.at(3)){
    cout << "Weak";
    return 0;
  }

  ans = "Weak";
  for(int i=0; i<3; ++i){
    if(s.at(i) != '9' && s.at(i) != (char)(s.at(i+1)-1) || s.at(i) == '9' && s.at(i+1) != '0') ans = "Strong";
  }
  
  cout << ans;
}
