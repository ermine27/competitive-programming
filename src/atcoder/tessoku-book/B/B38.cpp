/*
★４相当

左から順にAとBの両方を処理しようとすると処理が複雑になる。
A(草i<草i+1)の時と、B（草i>草i+1)の場合を別けたほうが処理が楽になる。
Bの処理をする時、Aの値との大きい方を選ぶようにすること。

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
    string s;
    cin >> n >> s;

    vi h(n, 1);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'A') {
            h[i + 1] = h[i] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'B') {
            h[i] = max(h[i], h[i + 1] + 1);
        }
    }
    rep(i, n) ans += h[i];
    cout << ans << endl;
    return 0;
}
