#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<string> Contest = {"ABC", "ARC", "AGC", "AHC"};
  string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
  for(string x: Contest){
    if(x!=s1 && x!=s2 && x!=s3){
      cout << x;
      return 0;
    }
  }
}
