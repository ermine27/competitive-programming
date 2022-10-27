#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  int len=s.length();
  char c;
  
  for(int i=0; i<len; ++i){
    c = s.at(i);
    if(! (i%2==0 && c>='a' && c<='z' || i%2==1 && c>='A' && c<='Z')){
      cout << "No";
      return 0;
    }
  }
  
  cout << "Yes";  
}
