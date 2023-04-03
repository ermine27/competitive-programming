#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || j == k || k == i)
                    continue;
                int dx1 = x[i] - x[j];
                int dx2 = x[i] - x[k];
                int dy1 = y[i] - y[j];
                int dy2 = y[i] - y[k];
                if (dx1 * dy2 == dx2 * dy1)
                    return true;
            }
        }
    }

    return false;
}

int main() {
    cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}
