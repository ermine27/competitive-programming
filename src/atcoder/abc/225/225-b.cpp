#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b,a2,b2,root;
  cin >> n >> a >> b >> a2 >> b2;
  if(a==a2 || a==b2) root = a;
  else if(b==a2 || b==b2) root = b;
  else {
    cout << "No";
    return 0;
  }

  for(int i=3; i<n; ++i){
    cin >> a >> b;
    if(a != root && b != root){
      cout << "No";
      return 0;
    }
  }
      
  cout << "Yes";
}
