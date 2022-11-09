#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // unique関数で重複した要素は右に集められる（削除はされない）
    // 戻り値に重複しない範囲の次を指すイテレータが得られるので、そこから最後までの要素を削除すれば重複のない配列ができる。
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 0; i < (int)a.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;

    return 0;
}
