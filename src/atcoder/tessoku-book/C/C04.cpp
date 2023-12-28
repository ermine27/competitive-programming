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
    set<ll> ans;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.insert(i);
            ans.insert(n / i);
        }
    }

    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
