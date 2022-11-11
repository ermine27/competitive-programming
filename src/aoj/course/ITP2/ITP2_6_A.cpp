#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << (binary_search(a.begin(), a.end(), k) ? 1 : 0) << endl;
    }

    return 0;
}
