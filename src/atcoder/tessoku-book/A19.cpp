#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, wmax;
    cin >> n >> wmax;
    vi w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    vl dp(wmax + 1);
    rep(i, n) {
        for (int j = wmax - w[i]; j >= 0; j--) {
            dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
