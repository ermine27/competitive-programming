#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isPrime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (isPrime(x)) ++ans;
    }

    cout << ans << endl;
    return 0;
}
