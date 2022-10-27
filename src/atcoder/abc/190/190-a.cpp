#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  if(c==0){
    --a;
  }
  
  if(a >= b){
    cout << "Takahashi";
  } else {
    cout << "Aoki" ;  
  }
}
