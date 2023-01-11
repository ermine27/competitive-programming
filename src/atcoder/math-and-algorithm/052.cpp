#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long nKr(int n, int a) {
    vector<long long> f(n + 1), fi(n + 1), iv(n + 1);
    f[0] = f[1] = 1;
    fi[0] = fi[1] = 1;
    iv[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * i % mod;
        iv[i] = mod - iv[mod % i] * (mod / i) % mod;
        fi[i] = fi[i - 1] * iv[i] % mod;
    }

    return f[n] * (fi[a] * fi[n - a] % mod) % mod;
}

// A=(i+1,j+2), B=(i+2,j+1)
// AとBの回数を求める
// 10^6 までなので全探索で求める
int main() {
    int x, y;
    cin >> x >> y;

    for (int a = 0; a <= x; a++) {
        int b = x - 2 * a;

        // bが負で成立してしまう場合があるのでそれも除外する
        if (b >= 0 && a + 2 * b == y) {
            cout << nKr(a + b, a) << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
