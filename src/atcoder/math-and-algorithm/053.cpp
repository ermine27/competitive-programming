/*
等差数列の総和
  a:初項、r:公比、n:項数
　S = Σ(a^k) = a(r^(n)-1}) / (r-1)

  a=1, r=4, n=n+1
  S = (4^{n+1}-1) / 3
*/

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a) { return modpow(a, mod - 2); }

int main() {
    long long n, ans;
    cin >> n;
    ans = (modpow(4, n + 1) - 1) * modinv(3) % mod;
    cout << ans << endl;
    return 0;
}
