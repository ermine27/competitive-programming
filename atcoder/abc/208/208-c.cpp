#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;


int main(){
    int n;
    ll k, kk, d;
    cin >> n >> k;

    vi a(n),b(n);
    rep(i,n) cin >> a[i];
    b = a;

    d = k / n;
    kk = k % n;

    sort(all(a));

    int ki = a[kk];

    rep(i,n) cout << (b[i] < ki ? d + 1 : d) << endl;
}