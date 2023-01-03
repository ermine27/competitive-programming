#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, l, r, cur = 0;
    cin >> t >> n;
    vector<int> imos(t + 1);

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        imos[l]++;
        imos[r]--;
    }

    for (int i = 0; i < t; i++) {
        cur += imos[i];
        cout << cur << endl;
    }
    return 0;
}
