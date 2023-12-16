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

// 全探索でもACはするが遅い
int main() {
    int n, d, ans = 0;
    cin >> n >> d;
    vi x(n), y(n);
    rep(i, n) { cin >> x[i] >> y[i]; }

    for (int i = 1; i <= d; i++) {
        int maxno = -1;
        for (int j = 0; j < n; j++) {
            if (x[j] <= i && y[j] > y[maxno]) {
                maxno = j;
            }
        }
        if (maxno == -1)
            continue;

        ans += y[maxno];
        y[maxno] = 0;
    }

    cout << ans << endl;
    return 0;
}

// 高速化。毎回その日に選べる死後の中でもらえる額が最大のものを選ぶ。
int main2() {
    int n, d, ans = 0;
    cin >> n >> d;
    map<int, vi> m;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        m[x - 1].push_back(y);
    }

    multiset<int> ms;
    rep(i, d) {
        int sz = m[i].size();
        rep(j, sz) { ms.insert(m[i][j]); }
        if (ms.size() > 0) {
            // multisetの場合、この書き方だと最大値が複数個あると全て削除してしまう
            // int x = *ms.rbegin();
            // ms.erase(x);
            int x = *ms.rbegin();
            ms.erase(ms.find(x));
            ans += x;
        }
    }

    cout << ans << endl;
    return 0;
}
