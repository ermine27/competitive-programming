#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,X;
  cin >> S;
  int sLen = S.length();
  X = "oxxoxxoxxoxx";

  for(int i=0; i<3; ++i){
    if(X.substr(i,sLen) == S){
      cout << "Yes";
      return 0;
    }
  } 
  cout << "No";
}
