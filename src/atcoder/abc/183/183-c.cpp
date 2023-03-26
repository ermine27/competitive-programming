#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> t[i][j];

    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = i;
    int ans = 0;

#if 0
    do {
        if (c[0] != 0)
            continue;
        int d = 0;
        for (int i = 0; i < n - 1; i++) {
            d += t[c[i]][c[i + 1]];
        }
        d += t[c[n - 1]][0];

        if (d == k)
            ans++;
    } while (next_permutation(c.begin(), c.end()));
#else
    // 本問では都市1からスタートするようにする必要があるが、
    // next_permutation() の引数を工夫することで余計な条件分岐をなくせる
    do {
        int d = 0;
        for (int i = 0; i < n; i++) d += t[c[i]][c[(i + 1) % n]];
        if (d == k)
            ans++;
    } while (next_permutation(c.begin() + 1, c.end()));
#endif

    cout << ans << endl;
    return 0;
}
