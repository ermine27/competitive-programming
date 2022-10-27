#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,x,ii,ans=0;
  cin >> n >> x;
  vector<int> a(n);
  vector<bool> b(n,false);
  for(int i=0; i<n; ++i){
    cin >> a.at(i);
    --a.at(i);
  }

  ii = x-1;
  do{
    ++ans;
    b.at(ii) = true;
    ii = a.at(ii);
  }while(b.at(ii) == false);
  
  cout << ans;
}
