#include <bits/stdc++.h>
using namespace std;

// ユークリッドの互除法を使って求める
int main() {
    long long a, b, m;
    cin >> a >> b;
    if (a < b)
        swap(a, b);

    while (a % b != 0) {
        m = a % b;
        a = b;
        b = m;
    }

    cout << b << endl;
    return 0;
}

// 別解１：gcd関数で求める
int main2() {
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}

// 別解２：素因数分解をして求める
int main3() {
    long long a, b, ans = 1LL;
    cin >> a >> b;
    map<long long, int> ap, bp;
    set<long long> s;

    auto f = [](long long n) {
        map<long long, int> ret;
        for (long long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                ret[i]++;
                n /= i;
            }
        }
        if (n > 1)
            ret[n]++;
        return ret;
    };

    ap = f(a);
    bp = f(b);

    for (auto it = ap.begin(); it != ap.end(); it++) s.insert(it->first);
    for (auto it = bp.begin(); it != bp.end(); it++) s.insert(it->first);
    for (auto it = s.begin(); it != s.end(); it++) {
        ans *= pow(*it, min(ap[*it], bp[*it]));
    }

    cout << ans << endl;
    return 0;
}
