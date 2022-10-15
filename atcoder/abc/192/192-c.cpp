#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()

int main(){
    string s,g1,g2;
    int k;
    cin >> s >> k;

    rep(i, k){
        g1 = s;
        sort(all(g1));
        g2 = g1;
        reverse(all(g2));
        s = to_string(stoll(g2) - stoll(g1));
    }

    cout << s;
}