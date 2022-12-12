#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    long long ans = 1;
    cin >> n >> r;

    for (int i = 0; i < r; i++) {
        ans *= n - i;
    }
    for (int i = 1; i <= r; i++) {
        ans /= i;
    }

    cout << ans << endl;
    return 0;
}
