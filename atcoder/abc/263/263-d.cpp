#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int n;
    ll l, r;
    cin >> n >> l >> r;
    vl a(n), ar(n), minl(n), minr(n);
    rep(i, n) cin >> a[i];

    minl[0] = min(a[0], l);
    repf(i, n - 1) minl[i] = min(minl[i - 1] + a[i], l * (i + 1));

    ar = a;
    reverse(all(ar));
    minr[0] = min(ar[0], r);
    repf(i, n - 1) minr[i] = min(minr[i - 1] + ar[i], r * (i + 1));

    reverse(all(minr));
    ll ans = LONG_LONG_MAX;
    rep(i, n - 1) chmin(ans, minl[i] + minr[i + 1]);
    cout << min({ans, minl[n - 1], minr[0]}) << endl;
    return 0;
}

// 少しコードを短くしたもの
int main2() {
    int n;
    ll l, r;
    cin >> n >> l >> r;
    vl a(n+2), minl(n+2), minr(n+2);
    repf(i, n) cin >> a[i];

    repf(i, n) minl[i] = min(minl[i - 1] + a[i], l * i);

    reverse(all(a));
    repf(i, n) minr[i] = min(minr[i - 1] + a[i], r * i);
    reverse(all(minr));

    ll ans = LONG_LONG_MAX;
    rep(i, n + 1) chmin(ans, minl[i] + minr[i + 1]);
    cout << ans << endl;
    return 0;
}
