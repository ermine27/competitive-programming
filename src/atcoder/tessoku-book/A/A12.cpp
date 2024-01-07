/*
K <= 10^9 なので順番にK枚目までを数えていく方法ではTLEする。
制約の2つ目のK<=10^9と3つ目のAi<=10^9より、答えも10^9以下であると分かる。
答えに対して二分探索をする。

x秒後において印刷できるチラシの枚数を求めるのはO(N)で行えるので、計算量はO(N * log 10^9)
log 10^9 ≒ 29.89 なので計算量としては十分間に合う。

二分探索の方針としては、K枚以上ならOK、K枚未満ならNGとして幅を狭めていく。
*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    // x秒以内にK枚以上印刷できるか
    auto check = [&](int x) -> bool {
        ll t = 0;
        rep(i, n) t += x / a[i];
        return t >= k;
    };

    // ng:印刷枚数がK枚未満になる最大値、ok:印刷枚数がK枚以上になる最小値
    int ng = -1, ok = 1e9;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;
    return 0;
}
