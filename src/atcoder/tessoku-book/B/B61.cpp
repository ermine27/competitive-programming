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
    int n, m;
    cin >> n >> m;
    vi c(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        c[a - 1]++;
        c[b - 1]++;
    }

    auto it = max_element(c.begin(), c.end());
    int ans = it - c.begin() + 1;

    cout << ans << endl;
    return 0;
}

int main2() {
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    cout << max_element(cnt.begin(), cnt.end(),
                        [](const auto& x, const auto& y) { return x.second < y.second; })
                ->first
         << endl;
}