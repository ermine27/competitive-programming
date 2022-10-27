#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> S(4);
  for(int i=0; i<4; ++i) cin >> S.at(i);

  if(S.at(0) == '.' && S.at(3) == '.' || S.at(1) == '.' && S.at(2) == '.'){
    cout << "No";
    return 0;
  }
    
  cout << "Yes";
}
