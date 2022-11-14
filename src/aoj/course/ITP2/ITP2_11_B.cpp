#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> b(k);
    for (int i = 0; i < k; ++i) cin >> b[i];

    for (int i = 0; i < 1 << n; ++i) {
        bitset<18> bs(i);
        bool ok = true;
        for (int j = 0; j < k; ++j) {
            if (!bs[b[j]]) ok = false;
        }

        if (ok == false) continue;

        cout << i << ':';
        for (int j = 0; j < n; ++j) {
            if (bs[j]) cout << ' ' << j;
        }
        cout << endl;
    }

    return 0;
}
