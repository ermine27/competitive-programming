#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long d = gcd(a, b);
    long double la = a, lb = b;
    long double x = la / d * lb;

    if (x > 1e18) {
        cout << "Large" << endl;
    } else {
        cout << a / d * b << endl;
    }

    return 0;
}
