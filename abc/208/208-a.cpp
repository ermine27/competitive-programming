#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a,b,min,max;
  cin >> a >> b;
  
  min=a;
  max=6*a;
  
  puts(min<=b && b<=max ? "Yes" : "No");
}
