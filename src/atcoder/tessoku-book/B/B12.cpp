#include <bits/stdc++.h>
using namespace std;

int main() {
    double n;
    cin >> n;
    double ok = 0.0, ng = cbrt(100000.0), mid;
    while (ng - ok > 0.001) {
        mid = (ok + ng) / 2.0;
        if (mid * mid * mid + mid < n)
            ok = mid;
        else
            ng = mid;
    }
    cout << setprecision(8) << ok << endl;
}
