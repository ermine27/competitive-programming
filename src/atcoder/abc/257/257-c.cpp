#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& x:a)
#define fore2(k,v,a) for(auto& [k,v] : a)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using mii = map<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;


int main(){
    int n;
    string s;
    cin >> n >> s;
    vi w(n);
    mii ma,mc,mm;
    mm[0] = 1;
    mm[INF+1] = 1;
    int na = 0, nc = 0, ca = 0, cc = 0;

    rep(i, n){
        int wi;
        cin >> wi;
        mm[wi]++;
        if(s[i] == '1'){
            ma[wi]++;
            ++na;
        } else {
            mc[wi]++;
            ++nc;
        }
    }

    int ans = 0;
    fore2(key,val,mm){
        int a;
        ca += ma[key];
        cc += mc[key];
        a = (na - ca) + cc;
        chmax(ans,a);
    }

    cout << ans << endl;
    return 0;
}
