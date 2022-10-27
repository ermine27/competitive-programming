#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n, x;
    cin >> n >> x;
    vl a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    ll ans = LLONG_MAX;
    ll fst = 0;

    int cc = min(n,x);
    rep(i,cc){
        ll t = 0LL;
        fst += a[i] + b[i];
        t = fst + b[i] * (x-i-1);
        chmin(ans, t);
    }

    cout << ans << endl;

    return 0;
}
