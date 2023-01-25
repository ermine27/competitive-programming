#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, f, cnt = 0;
    cin >> k >> n >> f;
    for (int i = 0; i < f; i++) {
        int a;
        cin >> a;
        cnt += a;
    }

    cout << max(-1, k * n - cnt) << endl;
    return 0;
}
