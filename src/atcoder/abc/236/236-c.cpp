#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    map<string,int> t;

    rep(i,n) cin >> s[i];
    string str;
    rep(i,m){
        cin >> str;
        t[str]=1;
    }

    rep(i,n) cout << (t.count(s[i]) ? "Yes" : "No") << endl;
}
