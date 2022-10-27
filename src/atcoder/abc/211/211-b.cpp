#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<string> s(4);
  for(int i=0; i<4; ++i){
    cin >> s.at(i);
    for(int j=0; j<i; ++j){
      if(s.at(i)==s.at(j)){
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
}
