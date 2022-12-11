#include <bits/stdc++.h>
using namespace std;

long long euclidean(long long a, long long b) {
    if (a < b)
        swap(a, b);

    while (a % b != 0) {
        long long m = a % b;
        a = b;
        b = m;
    }

    return b;
}

int main() {
    long long n, a, ans;
    cin >> n;
    cin >> ans;
    for (int i = 1; i < n; i++) {
        cin >> a;
        ans = euclidean(ans, a);
    }
    cout << ans << endl;
    return 0;
}
