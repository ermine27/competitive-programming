#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, s=0;
  cin >> n;
  vector<int> a(n), b(n);
    
  for(int i=0; i<n; ++i){
    cin >> a.at(i);
  }
  for(int i=0; i<n; ++i){
    cin >> b.at(i);
  }
  for(int i=0; i<n; ++i){
    s += a.at(i) * b.at(i);
  }
  
  puts(s==0 ? "Yes" : "No");  
}
