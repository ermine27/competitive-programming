#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k = 1, ans = 0;
    cin >> n;
    while (n > 0) {
        if (n % 2)
            ans += k;
        k *= 2;
        n /= 10;
    }

    cout << ans << endl;
    return 0;
}
