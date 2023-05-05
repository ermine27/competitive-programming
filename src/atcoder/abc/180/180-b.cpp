#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] = abs(x[i]);
    }
    long long d1 = x[0];
    long long d2 = x[0] * x[0];
    long long d3 = x[0];
    for (int i = 1; i < n; i++) {
        d1 += x[i];
        d2 += x[i] * x[i];
        d3 = max(d3, x[i]);
    }

    cout << fixed << setprecision(10);
    cout << d1 << endl << sqrt(d2) << endl << d3 << endl;
    return 0;
}
