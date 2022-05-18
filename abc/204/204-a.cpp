#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int x,y;
  cin >> x >> y;
  
  if(x==y){
    cout << x;
    return 0;
  }
  
  if(x==0 || y==0){
    if(x==1 || y==1) cout << 2;
    else cout << 1;
  }else{
    cout << 0;
  }
}
