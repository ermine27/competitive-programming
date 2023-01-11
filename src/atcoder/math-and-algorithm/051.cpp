#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main() {
    int x, y, n;
    cin >> x >> y;
    n = x + y;
    vector<long long> f(n + 1), fi(n + 1), iv(n + 1);
    f[0] = f[1] = 1;
    fi[0] = fi[1] = 1;
    iv[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * i % mod;
        iv[i] = mod - iv[mod % i] * (mod / i) % mod;
        fi[i] = fi[i - 1] * iv[i] % mod;
    }
    cout << f[n] * (fi[x] * fi[n - x] % mod) % mod << endl;
    return 0;
}
