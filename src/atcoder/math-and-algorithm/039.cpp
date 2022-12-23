#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, l, r, x;
    cin >> n >> q;
    vector<int> imos(n + 1);

    for (int i = 0; i < q; i++) {
        cin >> l >> r >> x;
        imos[l - 1] += x;
        imos[r] -= x;
    }

    for (int i = 1; i < n; i++) {
        if (imos[i] > 0)
            cout << '<';
        if (imos[i] < 0)
            cout << '>';
        if (imos[i] == 0)
            cout << '=';
    }
    cout << endl;
    return 0;
}
