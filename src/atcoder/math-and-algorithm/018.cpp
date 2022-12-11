#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> p(4, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        p[a / 100 - 1]++;
    }

    cout << 1LL * p[0] * p[3] + 1LL * p[1] * p[2] << endl;
    return 0;
}
