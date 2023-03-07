#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long x) {
    vector<long long> res;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) {
                res.push_back(x / i);
            }
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main() {
    long long n, ans = 1e12 + 9;
    cin >> n;
    vector<long long> d = divisor(n);
    for (int i = 0; i < (int)d.size(); i++) {
        ans = min(ans, d[i] + n / d[i]);
    }
    cout << ans * 2 << endl;
    return 0;
}
