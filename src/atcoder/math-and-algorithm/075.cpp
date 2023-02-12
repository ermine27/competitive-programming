#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> fact(n + 1), factinv(n + 1), inv(n + 1);
    fact[0] = fact[1] = 1;
    factinv[0] = factinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        factinv[i] = factinv[i - 1] * inv[i] % mod;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long p = fact[n - 1] * (factinv[i] * factinv[n - 1 - i] % mod) % mod;
        ans = (ans + (p * a[i])) % mod;
    }

    cout << ans << endl;
    return 0;
}
