#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
using ll = long long;
using vl = vector<long long>;
using vvl = vector<vl>;

const ll INF = 1e18;

int main() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    vvl dp1(n, vl(2));
    vvl dp2 = dp1;

    dp1[0][0] = 0;
    dp1[0][1] = INF;
    dp2[0][0] = INF;
    dp2[0][1] = a[0];
    for (int i = 1; i < n; ++i) {
        dp1[i][0] = dp1[i - 1][1];
        dp1[i][1] = min(dp1[i - 1][0], dp1[i - 1][1]) + a[i];
        dp2[i][0] = dp2[i - 1][1];
        dp2[i][1] = min(dp2[i - 1][0], dp2[i - 1][1]) + a[i];
    }

    cout << min({dp1[n - 1][1], dp2[n - 1][0], dp2[n - 1][1]}) << endl;
    return 0;
}
