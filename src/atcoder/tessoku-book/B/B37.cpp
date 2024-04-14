/*
★５相当

A37と同様、計算の方法を工夫してTLEしないようにする。
0～9までの数字が出てくる回数を数え上げて、それぞれの数字×出現回数とすれば計算量は落とせそう。

c(i,j) = 下からi桁目の数字がjとなる、0以上N以下の整数の個数とすると、

c(i,j) =
  N / 10^(i+1) * 10^i + 10^i  　j < 10^i の値の場合
  N / 10^(i+1) * 10^i + N mod 10^i + 1    j = 10^i の値の場合
  N / 10^(i+1) * 10^i    j > 10^i の値の場合

で求まるので、最後に各jにおいて j * c(i,j) の総和が求める答えになる。

出現回数の求め方については公式の解説を参照。
https://github.com/E869120/kyopro-tessoku/blob/main/editorial/chap06/chap06.pdf

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
    ll n;
    cin >> n;
    ll power, power2 = 1LL;

    vector<vl> cnt(15, vl(10, 0LL));
    rep(i, 15) {
        power = power2;
        power2 *= 10;
        ll digit = (n / power) % 10;
        rep(j, 10) {
            if (j < digit)
                cnt[i][j] = (n / power2) * power + power;
            if (j == digit)
                cnt[i][j] = (n / power2) * power + (n % power) + 1;
            if (j > digit)
                cnt[i][j] = (n / power2) * power;
        }
    }

    ll ans = 0LL;
    rep(i, 15) {
        rep(j, 10) { ans += 1LL * j * cnt[i][j]; }
    }
    cout << ans << endl;
    return 0;
}
