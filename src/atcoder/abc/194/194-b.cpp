#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for(int i=0; i<n; ++i){
    cin >> a.at(i) >> b.at(i);
  }

  int amin=100001,bmin=100001,ano,bno;
  for(int i=0; i<n; ++i){
    if(a.at(i)<amin){
      amin = a.at(i);
      ano = i;
    }
  }

  for(int i=0; i<n; ++i){
    if(i!=ano && b.at(i)<=bmin || i==ano && amin+b.at(i) < bmin){
      bmin=b.at(i);
      bno = i;
    }
  }

  if(ano == bno) cout << amin+bmin;
  else cout << max(amin,bmin);
}
