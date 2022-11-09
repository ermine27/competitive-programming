#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int com, b, e;
        cin >> com >> b >> e;

        if (com == 0) {
            cout << *min_element(a.begin() + b, a.begin() + e) << endl;
        } else {
            cout << *max_element(a.begin() + b, a.begin() + e) << endl;
        }
    }

    return 0;
}
