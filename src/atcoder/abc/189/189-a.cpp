#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  
  puts(s.at(0) == s.at(1) && s.at(1) == s.at(2) ? "Won" : "Lost");
}
