#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<string> st(n);
  string s,t;
  for(int i=0;i<n;++i){
    cin >> s >> t;
    st.at(i)=s+' '+t;
  }

  for(int i=0; i<n; ++i){
    for(int j=i+1; j<n; ++j){
      if(st.at(i)==st.at(j)){
        cout << "Yes";
        return 0;
      }
    }
  }
  
  cout << "No";
  return 0;
}
