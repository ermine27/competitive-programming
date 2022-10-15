#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n,m,k;
    cin >> n >> m;
    vi a(m), b(m);
    rep(i,m) cin >> a[i] >> b[i];
    cin >> k;
    vi c(k), d(k);
    rep(i,k) cin >> c[i] >> d[i];

    int ans = 0;

    rep(i,1<<k){
        bitset<16> bs = i;
        set<int> p;
        rep(j,k){
            p.insert(bs[j] ? c[j] : d[j]);
        }

        int cc = 0;
        rep(j,m){
            if(p.count(a[j]) && p.count(b[j])) ++cc;
        }

        chmax(ans,cc);
    }

    cout << ans;
}
