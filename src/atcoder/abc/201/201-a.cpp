#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,c;
  cin >> a >> b >> c;
  
  if(a-b==b-c || b-c==c-a || c-a==a-b) cout << "Yes";
  else cout << "No"; 
}
