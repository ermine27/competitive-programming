#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k = 1, ans = 0;
    cin >> n;
    while (n > k) {
        k *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
