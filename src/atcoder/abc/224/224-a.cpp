#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  cout << (s.at(s.length()-1) == 'r' ? "er" : "ist");
}
