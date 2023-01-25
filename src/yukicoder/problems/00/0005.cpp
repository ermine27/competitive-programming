#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, n;
    cin >> l >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    int k = 0;
    while (k < n && l - w[k] >= 0) {
        l -= w[k];
        k++;
    }
    cout << k << endl;
    return 0;
}
