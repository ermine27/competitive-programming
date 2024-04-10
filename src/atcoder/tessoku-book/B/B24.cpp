/*
★５問題

最長増加部分列(LIS)

A24の応用問題。
2次元LISを使う必要はなく、1次元で解ける。
ポイントは全ての箱を、縦の長さの昇順、横の長さの降順でソートすること。
ソート後、横の長さのLISが求める答えになる。
*/

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

int main() {
    int n;
    cin >> n;
    //
    vector<pair<int, int>> a(n);
    rep(i, n) {
        // int x, y;
        // cin >> x >> y;
        // a[i] = {x, -y};
        cin >> a[i].first >> a[i].second;
        // 2つ目の要素は降順でソートしたいので、-1倍することでsort関数一発でソートできる
        a[i].second *= -1;
    }
    sort(a.begin(), a.end());

    vi y2(n), dp(n);
    rep(i, n) y2[i] = -a[i].second;
    dp[0] = y2[0];
    int len = 1;
    rep(i, n) {
        if (dp[len - 1] < y2[i]) {
            dp[len++] = y2[i];
        } else {
            // int idx = lower_bound(dp.begin(), dp.begin() + len, y2[i]) - dp.begin();
            // dp[idx] = y2[i];
            *lower_bound(dp.begin(), dp.begin() + len, y2[i]) = y2[i];
        }
    }

    cout << len << endl;
    return 0;
}
