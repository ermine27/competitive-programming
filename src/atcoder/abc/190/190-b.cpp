#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,s,d;
  cin >> n >> s >> d;

  for(int i=0; i<n; ++i){
    int xi;
    int yi;
    cin >> xi >> yi;
    if(xi < s && yi > d){
      cout << "Yes";
      return 0;
    }
  }
  
  cout << "No";
}
