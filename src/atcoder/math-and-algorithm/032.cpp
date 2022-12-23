#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, a;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == x) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

int main2() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << (binary_search(a.begin(), a.end(), x) ? "Yes" : "No") << endl;
    return 0;
}
