#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long modpow(long long a, long long b) {
    if (b == 0)
        return 1;

    long long res = modpow(a, b / 2);
    if (b % 2 == 0)
        res = res * res % mod;
    else
        res = (((res * res) % mod) * a) % mod;
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << modpow(a, b) << endl;
    return 0;
}
