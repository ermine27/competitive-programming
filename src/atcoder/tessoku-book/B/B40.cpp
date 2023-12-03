/*
問題文の条件に沿って忠実にx<yの組み合わせを探すなら下のように2分探索を使えばできるが、
本問では組み合わせ数を求めるだけでいいので、片方だけ計算するだけでいい。
0と50だけ計算方法が変わるので場合分けする。
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
    int n, ans = 0;
    cin >> n;
    vi mod(100);
    rep(i, n) {
        int ai;
        cin >> ai;
        mod[ai % 100]++;
    }

    // 余りが1～49の場合（51～99は重複するので計算しない）
    for (int i = 1; i < 50; i++) {
        ans += mod[i] * mod[100 - i];
    }
    // 余りが0,50の場合
    for (int i = 0; i <= 50; i += 50) {
        ans += mod[i] * (mod[i] - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}

int main2() {
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> mod(100);
    rep(i, n) {
        int ai;
        cin >> ai;
        mod[ai % 100].push_back(i);
    }

    rep(i, 100) {
        if (i % 50 == 0) {
            ans += mod[i].size() * (mod[i].size() - 1) / 2;
        } else {
            rep(j, mod[i].size()) {
                ans += mod[100 - i].end() -
                       lower_bound(mod[100 - i].begin(), mod[100 - i].end(), mod[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
