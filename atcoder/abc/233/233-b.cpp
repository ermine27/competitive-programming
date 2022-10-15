#include <bits/stdc++.h>
using namespace std;

int main() {
  int L,R;
  string S,T;
  cin >> L >> R >> S;
  --L; --R;
  T=S;
  
  int f = R-L+1;
  for(int i=0; i<f; ++i){
    T.at(L+i) = S.at(R-i);
  }
 
  cout << T << endl;
}
