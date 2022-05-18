#include <bits/stdc++.h>
using namespace std;

#define repf(i,n) for(int i = 1; i <= (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  repf(i,9){
    repf(j,9){
      if(i*j == n){
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
