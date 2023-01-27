#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> score(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int i1, i2, s;
        cin >> i1 >> i2 >> s;
        score[i1][i2] = s;
    }

    vector<int> c(n);
    int ans = 0;
    for (int i = 0; i < n; i++) c[i] = i;
    do {
        int ss = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) ss += score[c[i]][c[j]];
        }
        ans = max(ans, ss);
    } while (next_permutation(c.begin(), c.end()));

    cout << ans << endl;
    return 0;
}
