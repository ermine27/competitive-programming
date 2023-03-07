#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> c1(n + 1), c2(n + 1);
    for (int i = 0; i < n; i++) {
        int c, p;
        cin >> c >> p;
        if (c == 1) {
            c1[i + 1] = c1[i] + p;
            c2[i + 1] = c2[i];
        } else {
            c1[i + 1] = c1[i];
            c2[i + 1] = c2[i] + p;
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << c1[r] - c1[l - 1] << ' ' << c2[r] - c2[l - 1] << endl;
    }

    return 0;
}
