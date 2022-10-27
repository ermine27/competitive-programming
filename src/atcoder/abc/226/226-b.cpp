#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n,ans=1;
  string a;
  getline(cin, a);
  n = stoi(a);

  vector<string> s;
  for(int i=0; i<n; ++i){
    getline(cin, a);
    s.push_back(a);
  }
  sort(s.begin(), s.end());

  a=s.at(0);
  for(int i=1; i<n; ++i){
    if(a != s.at(i)) ++ans;
    a = s.at(i);
  }

  cout << ans; 
}
