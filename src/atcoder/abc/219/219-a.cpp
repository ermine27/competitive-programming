#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  if(x>=90){
    cout << "expert";
    return 0;    
  }
  if(x>=70){
    cout << 90-x;
    return 0;    
  }
  if(x>=40){
    cout << 70-x;
    return 0;    
  }
  cout << 40-x;
}
