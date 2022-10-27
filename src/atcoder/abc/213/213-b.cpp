#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, ai, bottom=0, booby=0, bottomNo=0, boobyNo=0;
  cin >> n;
  
  for(int i=0; i<n; ++i){
    cin >> ai;
    if(ai > booby){
      swap(ai,booby);
      boobyNo = i+1;
      if(booby > bottom){
        swap(booby, bottom);
        swap(boobyNo, bottomNo);
      }
    }
  }
  cout << boobyNo ;
}
