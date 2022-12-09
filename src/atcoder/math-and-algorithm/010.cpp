#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) ans *= i;
    cout << ans << endl;
    return 0;
}
