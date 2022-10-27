#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1,s2,s3,t;
  cin >> s1 >> s2 >> s3 >> t;

  for(int i=0; i<t.length(); ++i){
    if(t.at(i)=='1') cout << s1;
    if(t.at(i)=='2') cout << s2;
    if(t.at(i)=='3') cout << s3;
  }
}
