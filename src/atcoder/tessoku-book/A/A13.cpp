#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

/*
最初に考えた解法
左の要素から順に、Ai + k の位置を二分探索で探す。
*/
#if 0
int main() {
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, n) cin >> a[i];
    a[n] = 2e9;
    rep(i, n - 1) {
        auto f = a.begin() + i;
        auto t = upper_bound(f, a.end(), a[i] + k);
        ans += t - f - 1;
    }

    cout << ans << endl;
    return 0;
}
#endif

/*
公式の解法
尺取り法を使って解く
*/
int main() {
    int n, k, rpos = 0;
    ll ans = 0;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    rep(lpos,n){
        while(rpos < n && a[rpos] - a[lpos] <= k)
            ++rpos;
        ans += rpos - lpos - 1;
    }

    cout << ans << endl;
    return 0;
}
