#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sa = a * (a + 1) / 2 % mod;
    long long sb = b * (b + 1) / 2 % mod;
    long long sc = c * (c + 1) / 2 % mod;
    cout << ((sa * sb % mod) * sc % mod) << endl;
    return 0;
}
