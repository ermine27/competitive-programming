#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int p, fi, ans=0;
  cin >> p;

  for(int i=10; i>0; --i){
    fi=1;
    for(int j=1; j<=i; ++j) fi *= j;
    int k=0;
    while(fi<=p && k<100){
      p -= fi;
      ++k;
      ++ans;
    }
  }
  
  cout << ans;
}
