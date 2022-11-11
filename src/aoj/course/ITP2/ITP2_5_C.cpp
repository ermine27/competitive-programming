#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n));
    for (int i = 0; i < n; ++i) cin >> a[1][i];
    a[0] = a[2] = a[1];

    prev_permutation(a[0].begin(), a[0].end());
    next_permutation(a[2].begin(), a[2].end());

    for (int i = 0; i < 3; ++i) {
        if ((i == 0 && a[0] >= a[1]) || (i == 2 && a[1] >= a[2])) continue;

        for (int j = 0; j < n; ++j) {
            if (j != 0) cout << ' ';
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
