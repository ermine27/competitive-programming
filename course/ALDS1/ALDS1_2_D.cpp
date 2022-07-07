#include <bits/stdc++.h>
using namespace std;

int cnt;
vector<int> g;

void insertionSort(vector<int> &a, int n, int g) {
    for (int i = g; i < n; ++i) {
        int v = a[i];
        int j = i - g;

        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j -= g;
            ++cnt;
        }
        a[j + g] = v;
    }
}

int shellSort(vector<int> &a, int n) {
    cnt = 0;

    int h = 1;
    while (h <= n) {
        g.push_back(h);
        h = 3 * h + 1;  // 間隔:h  h(n+1) = 3h(n)+1
    }

    reverse(g.begin(), g.end());

    for (int i = 0; i < (int)g.size(); ++i) {
        insertionSort(a, n, g[i]);
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int cnt = shellSort(a, n);
    cout << g.size() << endl;
    for (int i = 0; i < (int)g.size(); ++i) {
        if (i) cout << ' ';
        cout << g[i];
    }
    cout << endl;
    cout << cnt << endl;

    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }

    return 0;
}
