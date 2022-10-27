#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    int n;
    cin >> n;
    vi f(n + 1);
    f[0] = f[1] = 1;

    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }

    cout << f[n] << endl;
    return 0;
}
