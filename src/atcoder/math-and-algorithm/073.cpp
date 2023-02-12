#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0, p = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans + a[i] * p) % MOD;
        p = (p * 2) % MOD;
    }

    cout << ans << endl;
    return 0;
}