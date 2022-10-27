#include <bits/stdc++.h>
using namespace std;

int main(void) {
  double a,b,c,d,ans;
  cin >> a >> b >> c >> d;

  if(c*d==b){
    cout << -1;
    return 0;
  }
  ans=a/(c*d-b);
  if(ans<0){
    cout << -1;
    return 0;
  }
  cout << ceil(ans);
}
