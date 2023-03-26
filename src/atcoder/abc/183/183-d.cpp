#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    map<int, long long> imos;

    for (int i = 0; i < n; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        imos[s] += p;
        imos[t] -= p;
    }

    long long cur = 0;
    bool ok = true;

    for (auto& [k, v] : imos) {
        cur += v;
        if (cur > w) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
