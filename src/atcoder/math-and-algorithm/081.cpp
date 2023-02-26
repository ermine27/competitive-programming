#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    ans += n / 10000;
    n %= 10000;
    ans += n / 5000;
    n %= 5000;
    ans += n / 1000;
    cout << ans << endl;
    return 0;
}
