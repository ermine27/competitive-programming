#include <bits/stdc++.h>
using namespace std;

#define rrepf(i,n) for(int i = (int)(n); i > 0; --i)

int main() {
  int a,b,k,c=0;
  cin >> a >> b >> k;

  if(a<b) swap(a,b);
 
  rrepf(i,b){
    if(a%i == 0 && b%i == 0){
      ++c;
      if(c == k){
        cout << i;
        return 0;
      }
    }
  }
}

