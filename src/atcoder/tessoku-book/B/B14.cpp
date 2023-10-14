/*
半分全列挙
Nを2つのグループに分けることでNの最大は15になる。
15個であればビット全探索が可能。
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
    int n, an, bn;
    ll k;
    cin >> n >> k;
    an = n / 2;
    bn = n - an;
    vi a(an), b(bn);
    rep(i, n) {
        if (i < an)
            cin >> a[i];
        else
            cin >> b[i - an];
    }

    set<ll> sa = {0}, sb = {0};
    rep(i, 1 << an) {
        bitset<15> bs(i);
        int t = 0;
        rep(j, an) {
            if (bs[j])
                t += a[j];
        }
        sa.insert(t);
    }
    rep(i, 1 << bn) {
        bitset<15> bs(i);
        int t = 0;
        rep(j, bn) {
            if (bs[j])
                t += b[j];
        }
        sb.insert(t);
    }
    for (ll x : sa) {
        if (sb.find(k - x) != sb.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
