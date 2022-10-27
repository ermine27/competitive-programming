#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    string s;
    cin >> s;
    rep(i, 6 / s.length()) cout << s;
    return 0;    
}