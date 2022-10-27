#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &a, int n) {
    int cnt = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (a[j] < a[j - 1]) {
                ++cnt;
                swap(a[j], a[j - 1]);
            }
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int cnt = bubbleSort(a, n);

    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
