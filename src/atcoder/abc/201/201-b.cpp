#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  string si;
  int ti;
  cin >> n;
  vector<pair<int,string>> st;

  for(int i=0; i<n; ++i){
    cin >> si >> ti;
    st.push_back(make_pair(ti, si));
  }
  sort(st.begin(), st.end());
  reverse(st.begin(), st.end());

  cout << st.at(1).second;
}
