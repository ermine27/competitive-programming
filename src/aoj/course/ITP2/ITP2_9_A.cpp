#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector<int> c;
    // set_union 2つのソート済集合の和集合を得る
    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));

    for (int i = 0; i < (int)c.size(); ++i) {
        cout << c[i] << endl;
    }

    return 0;
}
