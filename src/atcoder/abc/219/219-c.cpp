#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()


int main(){
    map<char,char> x;
    char c;
    rep(i,26){
        cin >> c;
        x[c] = 'a' + i;
    }

    int n;
    cin >> n;
    vector<pair<string,string>> s;
    string si,si2;
    rep(i, n){
        cin >> si;
        si2 = si;
        rep(j, si.size()) si2[j] = x[si[j]];
        s.push_back(make_pair(si2,si));
    }

    sort(all(s));

    rep(i,n) cout << s[i].second << endl;
}
